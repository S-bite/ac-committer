import requests
import json
import time
from bs4 import BeautifulSoup
import os
import subprocess
import datetime


def ext(submission):
    if "C++" in submission["language"]:
        return ".cpp"
    elif "C" in submission["language"]:
        return ".c"
    elif "Py" in submission["language"]:
        return ".py"
    elif "Java" in submission["language"]:
        return ".java"
    elif "Text" in submission["language"]:
        return ".txt"
    else:
        print(
            f'unknown language : {submission["language"]}. ext() returns "".')
        return ""


def make_url(submission):
    return f'https://atcoder.jp/contests/{submission["contest_id"]}/submissions/{ submission["id"]}'


def get_code(url):
    print(url)
    try:
        html = requests.get(url).text
        soup = BeautifulSoup(html, features="html.parser")
        return soup.find("pre", {"id": "submission-code"}).text
    except Exception as e:
        print(e)
        return None


def commit(submission):
    code = get_code(make_url(submission))
    result = submission["result"]
    problem_id = submission["problem_id"]

    dirname = f'./submissions/{submission["contest_id"]}/{submission["problem_id"]}'
    filename = f'{result}_{submission["id"]}{ext(submission)}'
    filepath = f'{dirname}/{filename}'
    date = datetime.datetime.fromtimestamp(
        submission["epoch_second"], datetime.timezone(datetime.timedelta(hours=9)))
    if (code == None):
        print("err")
        return False
    os.makedirs(dirname, exist_ok=True)
    with open(filepath, "w+") as f:
        f.write(code)
    subprocess.run(["git", "add", filepath])
    subprocess.run(
        ["git", "commit", "-m", f'[{result}] {problem_id}', "--date", str(date)])
    return True


def get_submissions(username):
    url = "https://kenkoooo.com/atcoder/atcoder-api/results?user="+username
    response = requests.get(url)
    submissions = json.loads(response.text)
    return submissions


def main():
    username = "sbite"
    pushed = {}
    try:
        with open("pushedSubmissions.json", "r") as f:
            pushed = json.load(f)
    except Exception as e:
        pass
    print("load json")
    submissions = get_submissions(username)
    submissions = sorted(
        submissions, key=lambda submission: submission["epoch_second"])
    for submission in submissions:
        result = submission["result"]
        problem_id = submission["problem_id"]
        submission_id = submission["id"]
        if str(submission_id) in pushed:
            print("already pushed")
            continue
        print(problem_id, result)
        commit(submission)
        pushed[submission_id] = True
        with open("pushedSubmissions.json", "w") as f:
            json.dump(pushed, f)
        time.sleep(1)
    subprocess.run(["git", "add", "pushedSubmissions.json"])
    subprocess.run(["git", "commit", "-m","[update] update json"])
    subprocess.run(["git", "push", "origin","master"])

main()
