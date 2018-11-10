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
struct Pos{
  int x;
  int y;
};
inline bool operator<(const Pos& lhs, const Pos& rhs)
{
  return lhs.x < rhs.x;
}

class Robot{
private:
  string code;
public:
  int x,y,id=-1,ang=0;
  Pos stopPos;

  Robot();
  Robot(string,int);
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
Robot::Robot(string s,int i){
  x=SIZE/2;
  y=SIZE/2;
  id=i;


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
    int score;
    int stopMap[SIZE][SIZE];
  public:
    Robot robots[NUMROBOT];

    bool traceMap[SIZE][SIZE][NUMROBOT];

    Stage();
    Stage(string s[NUMROBOT]);

    int eval(Map);
    int diffEval(Map,bool[NUMROBOT]);
    void refreshRobots();
};
Stage::Stage(){
  rep(i,NUMROBOT) robots[i]=Robot();
  return;
}
Stage::Stage(string s[NUMROBOT]){
  rep(i,NUMROBOT) robots[i]=Robot(s[i],i);
  return;
}
void  Stage::refreshRobots(){
  rep(i,NUMROBOT) {
    robots[i].x=SIZE/2;
    robots[i].y=SIZE/2;
    robots[i].ang=0;
  }
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
int Stage::diffEval(Map m,bool canditates[NUMROBOT]){
  //cout<<st.size()<<endl;
  if (m.map[14][14]=='#') return -1;
  #define dump(r) cout<<"x:"<<r.x<<",y:"<<r.y<<",ang:"<<r.ang<<endl;
  score=0;
 rep(i,NUMROBOT) {
    Robot &r=robots[i];
    if (!canditates[r.id]) continue;

    stopMap[r.y][r.x]--;
    r.x=SIZE/2;r.y=SIZE/2;r.ang=0;
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
    traceMap[r.y][r.x][r.id]=true;
    }
    stopMap[r.y][r.x]++;
    r.stopPos=Pos({r.x,r.y});

  }
    rep(i,SIZE){
      rep(j,SIZE){
      if (stopMap[i][j]==1) score+=10;
      if (stopMap[i][j]==2) score+=3;
      if (stopMap[i][j]==3) score+=1;
    //  printf("% 3d" ,stopMap[i][j]);
    }
    //cout<<endl;
  }
  //cout<<score<<endl;
    return score;
}
int Stage::eval(Map m){
  if (m.map[14][14]=='#') return -1;
  refreshRobots();
  #define dump(r) cout<<"x:"<<r.x<<",y:"<<r.y<<",ang:"<<r.ang<<endl;
  score=0;
  rep(i,SIZE)rep(j,SIZE)stopMap[i][j]=0;
  rep(i,NUMROBOT){
    Robot &r=robots[i];
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
    traceMap[r.y][r.x][r.id]=true;
    }
    //dump(robots[0]);

    stopMap[r.y][r.x]++;
    r.stopPos=Pos({r.x,r.y});

  }
    rep(i,SIZE){
      rep(j,SIZE){
      if (stopMap[i][j]==1) score+=10;
      if (stopMap[i][j]==2) score+=3;
      if (stopMap[i][j]==3) score+=1;
    //  printf("% 3d" ,stopMap[i][j]);
    }

    //cout<<endl;
  }
  return score;
}
bool hasTrace(bool b[NUMROBOT]){
  rep(i,NUMROBOT)if(b[i]) return true;
  return false;
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
  int loop=0;
  while((double(clock()-c)/CLOCKS_PER_SEC<2.9) ){
    memcpy(old, m.map, sizeof(old));
    int cx,cy;

    do{
      cx=mt()%(SIZE-2)+1;
      cy=mt()%(SIZE-2)+1;

    }while(!hasTrace(s.traceMap[cy][cx]));
    m.map[cy][cx]=chip[mt()%6];

    int nowScore=s.diffEval(m,s.traceMap[cy][cx]);
    if (nowScore>maxScore){
      maxScore=nowScore;

    }else{
      memcpy(m.map,old, sizeof(old));

    }
    //break;
    loop++;
  }
  m.draw();
//  cout<<loop<<endl;
//  cout<<maxScore<<endl;
  return 0;
}
