int finish;
int persimpangan;
int buntu;


//way: 1 = utara, 2 = timur, 3 = selatan, 4 = barat

int *savedWay;
int curretWay=1;
string currentColor="black";

typedef struct {
  int way;
  string color;
} direction;

int n=0;
direction nextDirection;
direction *dirOpsion;

int GBFS() {
  if(finish) {
    return 1;
  } else {
    if(persimpangan) {
      savedWay[n]=curretWay;
      n++;
      nextWay=chooseDirection().way;
      if(goTo(nextWay)){;
        return GBFS();
      }
    } else {
      if (buntu) {
        if(backToPreviousNode()){
          return GBFS();
        }
      }
    }
  }
}

string chooseDirection() {
  direction next;
  inputDirection(dirOpsion);
  next = chooseShortestPath(dirOpsion);
  return next;
}


int backToPreviousNode(){
  int nextWay=turnBack(curretWay);
  curretWay=goAhead(nextWay);
  return 1;
}

void inputDirection(direction *dirOpsion){
  int way;
  i=0;
  way=forward(curretWay);
  if(currentColor!="white"){
    *dirOpsion[i].way=curretWay;
    *dirOpsion[i].color=currentColor;
    i++;
  }
  way=back(way);
  way=turnRight(way);
  if(currentColor!="white"){
    *dirOpsion[i].way=curretWay;
    *dirOpsion[i].color=currentColor;
    i++;
  }
  way=backRight(way);
  way=turnLeft(way);
  if(currentColor!="white"){
    *dirOpsion[i].way=curretWay;
    *dirOpsion[i].color=currentColor;
    i++;
  }
  way=backLeft(way);
}

int goTo(int nextWay){
  switch (curretWay) {
    case 1:{
      if(nextWay==1){
        curretWay=goAhead(curretWay);
      } else if(nextWay==2){
        curretWay=turnRight(curretWay)
        curretWay=goAhead(curretWay);
      }else if(nextWay==4){
        curretWay=turnLeft(curretWay)
        curretWay=goAhead(curretWay);
      }
      break;
    }
    case 2:{
      if(nextWay==2){
        curretWay=goAhead(curretWay);
      } else if(nextWay==3){
        curretWay=turnRight(curretWay)
        curretWay=goAhead(curretWay);
      }else if(nextWay==1){
        curretWay=turnLeft(curretWay)
        curretWay=goAhead(curretWay);
      }
      break;
    }
    case 3:{
      if(nextWay==3){
        curretWay=goAhead(curretWay);
      } else if(nextWay==4){
        curretWay=turnRight(curretWay)
        curretWay=goAhead(curretWay);
      }else if(nextWay==2){
        curretWay=turnLeft(curretWay)
        curretWay=goAhead(curretWay);
      }
      break;
    }
    case 4:{
      if(nextWay==4){
        curretWay=goAhead(curretWay);
      } else if(nextWay==1){
        curretWay=turnRight(curretWay)
        curretWay=goAhead(curretWay);
      }else if(nextWay==3){
        curretWay=turnLeft(curretWay)
        curretWay=goAhead(curretWay);
      }
      break;
    }
  }
  return 1;
}
