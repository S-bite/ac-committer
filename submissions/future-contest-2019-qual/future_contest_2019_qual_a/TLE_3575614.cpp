#include<bits/stdc++.h>
#include<stdio.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define SIZE 29
#define OPLEN 300
#define NUMROBOT 500
using namespace std;
random_device rnd;
mt19937 mt(rnd());
char op[3]={'S','R','L'};

char chip[6]={'.','#','D','T','L','R'};


class Robot{
private:
  string code;
public:
  int x,y,ang=0;
  Robot();
  Robot(string);
  char getop(int);

};

Robot::Robot(){
  x=SIZE/2;
  y=SIZE/2;
  rep(i,OPLEN){
    int r=mt()%100;
    if (r>=50) code+="S";
    else if (r>=25) code+="R";
    else code+="L";
  }
  //code="SSSSLSSSSS";
  return;
}
Robot::Robot(string s){
  x=SIZE/2;
  y=SIZE/2;
  code=s;
  return;
}


char Robot::getop(int i){
  return code[i];
}
class Map{
private:
public:
  char map[SIZE][SIZE];

  Map();
  Map copy();
  void draw();
};

Map::Map(){
  rep(i,SIZE){
    rep(j,SIZE){
      if (i==0 or i==SIZE-1 or j==0 or j==SIZE-1) map[i][j]='#';
      else map[i][j]='.';//chip[mt()%6];
    }
  }
  map[SIZE/2][SIZE/2]='.';
}


void Map::draw(){
  rep(i,SIZE){
    rep(j,SIZE){
      cout<<map[i][j];
    }
    cout<<"\r\n";
  }
  return ;
}


class Stage{
  private:
    void move(Robot&,char,Map);
    Robot robots[NUMROBOT];
    int score;
    int stopMap[SIZE][SIZE];
  public:
    Stage();
    Stage(string s[NUMROBOT]);

    int eval(Map);
    void refreshRobots();
};
Stage::Stage(){
  rep(i,NUMROBOT) robots[i]=Robot();
  return;
}
Stage::Stage(string s[NUMROBOT]){
  rep(i,NUMROBOT) robots[i]=Robot(s[i]);
  return;
}
void  Stage::refreshRobots(){
  rep(i,NUMROBOT) robots[i]=Robot();
  return ;
}

void Stage::move(Robot &r,char op,Map m){
  #define islegal(x,y) (x>=0 and x<=SIZE and y>=0 and y<=SIZE and m.map[y][x]!='#')

  if (op=='S'){
    int my=r.y+(1-r.ang%2)*(r.ang-1);
    int mx=r.x+(r.ang%2)*(r.ang-2);
    if (islegal(mx,my)){
      r.x=mx;
      r.y=my;
    }
  }else if(op=='R') {
    r.ang=(r.ang+3)%4;
  }else if(op=='L') {
    r.ang=(r.ang+1)%4;
  }else{
    cout<<"unknown command:"<<op<<endl;
  }

}

int Stage::eval(Map m){
  #define dump(r) cout<<"x:"<<r.x<<",y:"<<r.y<<",ang:"<<r.ang<<endl;
  score=0;
  rep(i,SIZE)rep(j,SIZE)stopMap[i][j]=0;
  rep(i,NUMROBOT){
    Robot r=robots[i];
    rep(j,OPLEN){
      char op = r.getop(j);
      char chip=m.map[r.y][r.x];
    //  cout<<"op:"<<op<<",chip:"<<chip<<endl;
    //  dump(r);
      if (chip=='.'){
          move(r,op,m);
      }else if(chip=='R'){
          if (op=='L') op='R';
          move(r,op,m);
      }else if(chip=='L'){
          if (op=='R') op='L';
          move(r,op,m);
      }else if(chip=='D'){
          rep(k,2)move(r,op,m);
      }else if(chip=='T'){
          rep(k,3)move(r,op,m);
      }
    //  dump(r);
    }
    stopMap[r.y][r.x]++;
  }
    rep(i,SIZE){
      rep(j,SIZE){
      if (stopMap[i][j]==1) score+=10;
      if (stopMap[i][j]==2) score+=3;
      if (stopMap[i][j]==3) score+=1;
      //printf("% 3d" ,stopMap[i][j]);
    }
    //cout<<endl;
  }
  return score;
}
int main(){
  clock_t c=clock();
  int _,__,___;
  cin>>_>>__>>___;
  string codes[NUMROBOT];
  rep(i,NUMROBOT)cin>>codes[i];
  Map m=Map();
  Stage s=Stage(codes);

  char old[SIZE][SIZE];
  int changeOnce=30;
  int maxScore=s.eval(m);
  while(true){
    if (double(clock()-c)/CLOCKS_PER_SEC>5.0) break;
    memcpy(old, m.map, sizeof(old));
    rep(j,changeOnce)m.map[mt()%(SIZE-2)+1][mt()%(SIZE-2)+1]=chip[mt()%6];
    int nowScore=s.eval(m);
    if (nowScore>maxScore){
      maxScore=nowScore;
    }else{
      memcpy(m.map,old, sizeof(old));
    }
  }
  m.draw();
  
  return 0;
}
