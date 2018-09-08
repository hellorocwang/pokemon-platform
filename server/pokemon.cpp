#include "pokemon.h"
#include <iostream>
#include <ctime>
#include <QTime>
#include <cstdlib>
#include <cmath>
#include <QDebug>

int AttituRelate[17][17]={
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0,-1,
    0,-1,-1, 0, 1, 1, 0, 0, 0, 0, 0, 1,-1, 0,-1, 0, 1,
    0, 1,-1,-1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,-1, 0, 0,
    0,-1, 1,-1, 0, 0, 0,-1, 1,-1, 0,-1, 1, 0,-1, 0,-1,
    0, 0, 1,-1,-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
    0,-1,-1, 1, 0,-1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0,-1,
    1, 0, 0, 0, 0, 1, 0,-1, 0,-1,-1,-1, 1, 0, 0, 1, 1,
    0, 0, 0, 1, 0, 0, 0,-1,-1, 0, 0, 0,-1,-1, 0, 0, 0,
    0, 1, 0,-1, 1, 0, 0, 1, 0, 0, 0,-1, 1, 0, 0, 0, 1,
    0, 0, 0, 1,-1, 0, 1, 0, 0, 0, 0, 1,-1, 0, 0, 0,-1,
    0, 0, 0, 0, 0, 0, 1, 1, 0, 0,-1, 0, 0, 0, 0, 0,-1,
    0,-1, 0, 1, 0, 0,-1,-1, 0,-1, 1, 0, 0,-1, 0, 1,-1,
    0, 1, 0, 0, 0, 1,-1, 0,-1, 1, 0, 1, 0, 0, 0, 0,-1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,-1,-1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,-1,
    0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1, 0, 0, 1, 0,-1,-1,
    0,-1,-1, 0,-1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,-1
};

pokemon::pokemon()
{
    HP = 0;
    nowHP = HP;
    Attack = 0;
    nowAttack = Attack;
    Defense = 0;
    nowDefense = Defense;
    Sp_Atk = 0;
    nowSp_Atk = Sp_Atk;
    Sp_Def = 0;
    nowSp_Def = Sp_Def;
    Speed = 0;
    nowSpeed = Speed;
    Value = 0;
    Level = 0;
    Experience = 0;
    nowExperience = 0;
    //skill = new pokeskill();
}

int pokemon::getAttack(){
    return Attack;
}

int pokemon::getnowAttack(){
    return nowAttack;
}

int pokemon::getDefense(){
    return Defense;
}

int pokemon::getnowDefense(){
    return nowDefense;
}

int pokemon::getHP(){
    return HP;
}

int pokemon::getnowHP(){
   return nowHP;
}

int pokemon::getSpeed(){
    return Speed;
}

int pokemon::getnowSpeed(){
    return nowSpeed;
}

int pokemon::getSp_Atk(){
    return Sp_Atk;
}

int pokemon::getnowSp_Atk(){
    return nowSp_Atk;
}

int pokemon::getSp_Def(){
    return Sp_Def;
}

int pokemon::getnowSp_Def(){
    return nowSp_Def;
}

int pokemon::getValue(){
    return Value;
}

int pokemon::getLevel(){
    return Level;
}

int pokemon::getlevelMax(){
    return levelMax;
}

vector<int> pokemon::getAttitude(){
     return Attitude;
}

int pokemon::getExperience(){
    return Experience;
}

int pokemon::getnowExperience(){
    return nowExperience;
}

void pokemon::setAttack(int attack){
    Attack = attack;
    nowAttack = attack;
}

void pokemon::setnowAttack(int nowattack){
    nowAttack = nowattack;
}

void pokemon::setDefense(int defense){
    Defense = defense;
    nowDefense = defense;
}

void pokemon::setnowDefense(int nowdefense){
    nowDefense = nowdefense;
}

void pokemon::setHp(int hp){
    HP = hp;
    nowHP = hp;
}

void pokemon::setnowHp(int add){
    nowHP = nowHP + add;
    if(nowHP < 0)
        nowHP = 0;
}

void pokemon::setSpeed(int speed){
    Speed = speed;
    nowSpeed = speed;
}

void pokemon::setnowSpeed(int nowspeed){
    nowSpeed = nowspeed;
}

void pokemon::setSp_Atk(int spatk){
    Sp_Atk = spatk;
    nowSp_Atk = spatk;
}

void pokemon::setnowSp_Atk(int spatk){
    nowSp_Atk = spatk;
}

void pokemon::setSp_Def(int spdef){
    Sp_Def = spdef;
    nowSp_Def = spdef;
}

void pokemon::setnowSp_Def(int nowspdef){
    nowSp_Def = nowspdef;
}

void pokemon::setnowExp(int nowExp){
    nowExperience = nowExp;
}

void pokemon::setValue(int value){
    Value = value;
}

void pokemon::addAttitude(int att){
    Attitude.push_back(att);
}

void pokemon::deleteAttitude(){
    Attitude.clear();
}

void pokemon::setLevel(int level){
        Level = level;
}

void pokemon::setlevelMax(int num){
    levelMax = num;
}

void pokemon::setExperience(){
    Experience = Level * Level;
}

void pokemon::levelUPHP(int number){
    HP = HP + number;
    nowHP = HP;
}

void pokemon::levelUPHP(int number, int level){
    HP = HP + number * level;
    nowHP = HP;
}

void pokemon::levelUPAttack(int number){
    Attack = Attack + number;
    nowAttack = Attack;
}

void pokemon::levelUPAttack(int number, int level){
    Attack = Attack + number * level;
    nowAttack = Attack;
}

void pokemon::levelUPDefense(int number){
    Defense = Defense + number;
    nowDefense = Defense;
}

void pokemon::levelUPDefense(int number, int level){
    Defense = Defense + number * level;
    nowDefense = Defense;
}

void pokemon::levelUPSp_Atk(int number){
    Sp_Atk = Sp_Atk + number;
    nowSp_Atk = Sp_Atk;
}

void pokemon::levelUPSp_Atk(int number, int level){
    Sp_Atk = Sp_Atk + number * level;
    nowSp_Atk = Sp_Atk;
}

void pokemon::levelUPSp_Def(int number){
    Sp_Def = Sp_Def + number;
    nowSp_Def = Sp_Def;
}

void pokemon::levelUPSp_Def(int number, int level){
    Sp_Def = Sp_Def + number * level;
    nowSp_Def = Sp_Def;
}

void pokemon::levelUPSpeed(int number){
    Speed = Speed + number;
    nowSpeed = Speed;
}

void pokemon::levelUPSpeed(int number, int level){
    Speed = Speed + number * level;
    nowSpeed = Speed;
}

int pokemon::getcofHPGrow(){
    return cofHPGrow;
}

int pokemon::getcofAttackGrow(){
    return cofAttackGrow;
}

int pokemon::getcofDefenseGrow(){
    return cofDefenseGrow;
}

int pokemon::getcofSp_AtkGrow(){
    return cofSp_AtkGrow;
}

int pokemon::getcofSp_DefGrow(){
    return cofDefenseGrow;
}

int pokemon::getcofSpeedGrow(){
    return cofSpeedGrow;
}

void pokemon::setcofHPGrow(int cof){
    cofHPGrow = cof;
}

void pokemon::setcofAttackGrow(int cof){
    cofAttackGrow = cof;
}

void pokemon::setcofDefenseGrow(int cof){
    cofDefenseGrow = cof;
}

void pokemon::setcofSp_AtkGrow(int cof){
    cofSp_AtkGrow = cof;
}

void pokemon::setcofSp_DefGrow(int cof){
    cofSp_DefGrow = cof;
}

void pokemon::setcofSpeedGrow(int cof){
    cofSpeedGrow = cof;
}

void pokemon::levelUP(){
    if(Level < levelMax){
        Level ++;
        setLevel(Level);
        setExperience();
        levelUPHP(getcofHPGrow());
        levelUPAttack(getcofAttackGrow());
        levelUPDefense(getcofDefenseGrow());
        levelUPSp_Atk(getcofSp_AtkGrow());
        levelUPSp_Def(getcofDefenseGrow());
        levelUPSpeed(getcofSpeedGrow());
    }

}

void pokemon::levelUP(int level){
    if(Level < levelMax){
        setLevel(getLevel() + level);
        setExperience();
        levelUPHP(getcofHPGrow() ,level);
        levelUPAttack(getcofAttackGrow() ,level);
        levelUPDefense(getcofDefenseGrow() ,level);
        levelUPSp_Atk(getcofSp_AtkGrow() ,level);
        levelUPSp_Def(getcofDefenseGrow() ,level);
        levelUPSpeed(getcofSpeedGrow() ,level);
    }
}

void pokemon::expUP(int number){
    int judge = 0;
    int num = number + 30*Level;
    if(nowExperience == Experience){
        levelUP();
        nowExperience = 0;
    }
    while(nowExperience + num >= Experience){
        levelUP();
        num = num - (Experience - nowExperience);
        if(Level % 10 == 0){
            nowExperience = 0;
            judge = 1;
        }
    }
    if(judge == 0)  nowExperience += num;
}

QString pokemon::returnPokename(){

}

QString pokemon::returnInitialname(){

}

pokeskill * pokemon::skillInitial(){
    skill = new pokeskill();
    return skill;
}

/*--------------------------------------------------------------*/

pokeskill::pokeskill()
{
    srand(unsigned(time(0)));
    keepSkill[0] = 0;
    keepSkill[1] = -1;
    keepSkill[2] = -1;
    keepSkill[3] = -1;
}

int pokeskill::getFirstSkill(){
    return keepSkill[1];
}

int pokeskill::getSecondSkill(){
    return keepSkill[2];
}

int pokeskill::getThirdSkill(){
    return keepSkill[3];
}

int pokeskill::randomSkill(){
    srand(unsigned(time(0)));
    return rand() % maxskill + 1;
}

int pokeskill::releaseSkill(int skill,int peopleNum){
    int i = returnRandomskill();
    while(true){
        if(skillStyle[skill] == 0){
            while(skillStyle[skill] == 0){
                i = returnRandomskill();
                skill = keepSkill[i];
                if(peopleNum == 1){
                    while(skillStyle[skill] != 1){
                        i = returnRandomskill();
                        skill = keepSkill[i];
                    }
                    return skill;
                }
            }
            return skill;
        }
        else if(peopleNum == 1){
            skill = keepSkill[i];
            while(skillStyle[skill] > 1){
                i = returnRandomskill();
                skill = keepSkill[i];
            }
            return skill;
        }
        else{
            i = returnRandomskill();
            return keepSkill[i];
        }
    }
}

float pokeskill::randomBetween(float a,float b){
    srand(unsigned(time(0)));
    int A = a*100;
    int B = b*100;
    return ((float)(A + rand()%(B - A + 1 )))/100;
}

int pokeskill::ranBetween(int a,int b){
    return a + rand()%(b - a + 1 );
}

int pokeskill::returnRandomskill(){
    int i;
    for(i = 0;keepSkill[i] != -1 && i<3;i++);
    int skill = ranBetween(0,i-1);
    return skill;
}

bool pokeskill::nofullskill(){
    if(keepSkill[3] == -1)
        return true;
    else
        return false;
}

bool pokeskill::addskill(int skill){
    if(nofullskill()){
        int i;
        for(i = 1;keepSkill[i] != -1;i++){
            if(keepSkill[i] == skill)
                return false;
        }
        keepSkill[i] = skill;
        return true;
    }
    else
        return false;
}

bool pokeskill::addrandomskill(){
    if(nofullskill()){
        int i;
        int j = 5;
        int skill[6];
        int temp;
        for(i = 0;i < 6;i++){
            skill[i] = i + 1;
        }
        for(i = 1;keepSkill[i] != -1&&i < 3;i++){
            temp = skill[keepSkill[i]-1];
            skill[keepSkill[i]-1] = skill[j];
            skill[j] = temp;
            j--;
        }
        temp = ranBetween(0,j);
        keepSkill[i] = skill[temp];
        return true;
    }
    else
        return false;
}


int pokeskill::getInjure(pokemon A,pokemon B,int AttRa){
    float a,d;
    if(AttRa >= 1){
        a = A.getnowSp_Atk();
        d = B.getnowDefense();
    }
    else if(AttRa <= -1){
        a = A.getnowAttack();
        d = B.getnowSp_Def();
    }
    else{
        a = A.getnowAttack();
        d = B.getnowDefense();
    }
    return (2*a*a)/(d*sqrt(d)/10);
}

int pokeskill::getAttRelate(int attitude1, pokemon B){
    vector<int> b = B.getAttitude();
    int sum = 0;
    while(!b.empty()){
        sum = sum + AttituRelate[attitude1][b.back()];
        b.pop_back();
    }
    return sum;
}

void pokeskill::deleteSkill(){
    keepSkill[0] = 0;
    keepSkill[1] = -1;
    keepSkill[2] = -1;
    keepSkill[3] = -1;
}

void pokeskill::skillEffect(pokemon &A , pokemon &B, int skill){

}

QString pokeskill::returnSkillName(int skill){
    return "false";
}

Bulbasaurskill::Bulbasaurskill(){
    Tackle = 0;
    Synthesis = 1;
    Growth = 2;
    LeechSeed = 3;
    PoisonPowder = 4;
    RazorLeaf = 5;
    SeedBomb = 6;
    skillStyle[Tackle] = 1;
    skillStyle[Synthesis] = 0;
    skillStyle[Growth] = 0;
    skillStyle[LeechSeed] = 0;
    skillStyle[PoisonPowder] = 5;
    skillStyle[RazorLeaf] = 1;
    skillStyle[SeedBomb] = 1;
}

void Bulbasaurskill::skillEffect(pokemon &A ,pokemon &B, int skill){
    RoundOver C;
    int tempNum;
    if(skill == Tackle){
        tempNum = randomBetween(0.95,1.05)* getInjure(A,B,getAttRelate(NORMAL ,B));
        B.setnowHp(0 - tempNum);
        qDebug()<<"Tackle:-"<<tempNum<<"HP";
    }
    else if(skill == PoisonPowder){
        B.setnowAttack(0.95 * B.getnowAttack());
        C.move = ATTACK;
        C.count = 3;
        C.num = 0.95;
        B.continueBuff.push_back(C);
        B.setnowSpeed(0.95 * B.getnowSpeed());
        C.move = SPEED;
        C.count = 3;
        C.num = 0.95;
        B.continueBuff.push_back(C);
        B.setnowHp(0 - randomBetween(1,2)* 0.2*getInjure(A,B,getAttRelate(POISON ,B)));
        C.move = LIFE;
        C.count = 3;
        C.num = 0 - 0.2*getInjure(A,B,getAttRelate(POISON ,B));
        B.continueBuff.push_back(C);
        qDebug()<<"PoisonPowder";
    }
    else if(skill == Growth){
        A.setnowAttack(1.15 * A.getnowAttack());
        C.move = ATTACK;
        C.count = 3;
        C.num = 1.15;
        A.continueBuff.push_back(C);
        qDebug()<<"Growth";
        A.setnowDefense(1.15 * A.getnowDefense());
        C.move = DEFENSE;
        C.count = 2;
        C.num = 1.15;
        A.continueBuff.push_back(C);
        A.setnowSp_Atk(1.1 * A.getnowSp_Atk());
        C.move = SPATK;
        C.count = 2;
        C.num = 1.1;
        A.continueBuff.push_back(C);
        A.setnowSp_Def(1.1 * A.getnowSp_Def());
        C.move = SPDEF;
        C.count = 2;
        C.num = 1.1;
        A.continueBuff.push_back(C);
    }
    else if(skill == LeechSeed){
        B.setnowHp(0 - randomBetween(0.85,1.25) * 0.3*getInjure(A,B,getAttRelate(GRASS ,B)));
        qDebug()<<"LeechSeed";
        B.setnowHp(0 - randomBetween(0.9,1.2) * 0.35*getInjure(A,B,getAttRelate(GRASS ,B)));
        qDebug()<<"LeechSeed";
        B.setnowHp(0 - randomBetween(0.95,1.15) * 0.4*getInjure(A,B,getAttRelate(GRASS ,B)));
        qDebug()<<"LeechSeed";
    }
    else if(skill == Synthesis){
        A.setnowAttack(1.8 * A.getnowAttack());
        C.move = ATTACK;
        C.count = 2;
        C.num = 1.15;
        A.continueBuff.push_back(C);
        A.setnowSpeed(1.5 * A.getnowSpeed());
        C.move = SPEED;
        C.count = 2;
        C.num = 1.5;
        A.continueBuff.push_back(C);
        qDebug()<<"Synthesis";
    }
    else if(skill == RazorLeaf){
        B.setnowHp(0 - randomBetween(0.98,1.05)* 1.1 * getInjure(A,B,getAttRelate(GRASS ,B)));
        qDebug()<<"RazorLeaf";
        B.setnowDefense(0.9 * B.getnowHP());
        C.count = 2;
        C.move = DEFENSE;
        C.num = 0.9;
        B.continueBuff.push_back(C);
    }
    else if(skill == SeedBomb){
        B.setnowHp(0 - 1.2 * randomBetween(0.9,1.2)* getInjure(A,B,getAttRelate(GRASS ,B)));
        qDebug()<<"SeedBomb";
    }
    else;
}

QString Bulbasaurskill::returnSkillName(int skill){
    switch(skill){
        case 0:
            return "Tackle";
        case 1:
            return "Synthesis";
        case 2:
            return "Growth";
        case 3:
            return "LeechSeed";
        case 4:
            return "PoisonPowder";
        case 5:
            return "RazorLeaf";
        case 6:
            return "SeedBomb";
        default:
            return "false";
    }
}

Charmanderskill::Charmanderskill(){
    Scratch = 0;
    Smokescreen = 1;
    DragonRage = 2;
    Ember = 3;
    Flameburst = 4;
    Heatwave = 5;
    FlareBlitz = 6;
    skillStyle[Scratch] = 1;
    skillStyle[Smokescreen] = 0;
    skillStyle[DragonRage] = 0;
    skillStyle[Ember] = 1;
    skillStyle[Flameburst] = 1;
    skillStyle[Heatwave] = 5;
    skillStyle[FlareBlitz] = 1;
}

void Charmanderskill::skillEffect(pokemon &A, pokemon &B, int skill){
    RoundOver C;
    if(skill == Scratch){
        B.setnowHp(0 - randomBetween(0.95,1.05)* getInjure(A,B,getAttRelate(FIRE ,B)));
        qDebug()<<"Scratch";
    }
    else if(skill == Ember){
        B.setnowDefense(0.9 * B.getnowDefense());
        C.move = ATTACK;
        C.count = 3;
        C.num = 0.9;
        B.continueBuff.push_back(C);
        B.setnowSpeed(0.9 * B.getnowSpeed());
        C.move = SPEED;
        C.count = 3;
        C.num = 0.9;
        B.continueBuff.push_back(C);
        B.setnowHp(0 - 0.85*randomBetween(0.95,1.05)* getInjure(A,B,getAttRelate(FIRE ,B)));
        qDebug()<<"Ember";
    }
    else if(skill == Smokescreen){
        A.setnowDefense(1.1 * A.getnowDefense());
        C.move = DEFENSE;
        C.count = 4;
        C.num = 1.2;
        A.continueBuff.push_back(C);
        A.setnowSp_Def(1.1 * A.getnowDefense());
        C.move = SPDEF;
        C.count = 4;
        C.num = 1.2;
        A.continueBuff.push_back(C);
        B.setnowAttack(0.9 * B.getnowAttack());
        C.move = ATTACK;
        C.count = 4;
        C.num = 0.85;
        B.continueBuff.push_back(C);
        qDebug()<<"Smokescreen";
    }
    else if(skill == DragonRage){
        A.setnowAttack(1.2 * A.getnowAttack());
        C.move = ATTACK;
        C.count = 3;
        C.num = 1.2;
        A.continueBuff.push_back(C);
        A.setnowSp_Atk(1.2 * A.getnowSp_Atk());
        C.move = SPATK;
        C.count = 3;
        C.num = 1.2;
        A.continueBuff.push_back(C);
        A.setnowSpeed(1.1 * A.getnowDefense());
        C.move = SPEED;
        C.count = 3;
        C.num = 1.1;
        A.continueBuff.push_back(C);
        qDebug()<<"DragonRage";
    }
    else if(skill == Flameburst){
        B.setnowHp(0 - randomBetween(0.8,1.2)* 1.2 * getInjure(A, B, FIRE));
        qDebug()<<"Flameburst";
    }
    else if(skill == Heatwave){
        B.setnowHp(0 - 0.3 * getInjure(A, B, FIRE));
        qDebug()<<"Heatwave";
        B.setnowSpeed(0.9 * B.getnowSpeed());
        C.move = SPEED;
        C.count = 3;
        C.num = 0.95;
        B.continueBuff.push_back(C);
        C.move = LIFE;
        C.count = 2;
        C.num = 0.3;
        B.continueBuff.push_back(C);
    }
    else if(skill == FlareBlitz){
         B.setnowHp(0 - 1.1 * getInjure(A, B, FIRE));
         qDebug()<<"FlareBlitz";
         B.setnowSpeed(0.9 * B.getnowSpeed());
         C.move = SPEED;
         C.count = 2;
         C.num = 0.75;
         B.continueBuff.push_back(C);
    }
    else;
}

QString Charmanderskill::returnSkillName(int skill){
    switch (skill) {
    case 0:
        return "Scratch";
    case 1:
        return "Smokescreen";
    case 2:
        return "DragonRage";
    case 3:
        return "Ember";
    case 4:
        return "Flameburst";
    case 5:
        return "Heatwave";
    case 6:
        return "FlareBlitz";
    default:
        return "false";
    }
}


SquirtleSkill::SquirtleSkill(){
    Tackle = 0;
    RainDance = 1;
    Withdraw = 2;
    WaterPulse = 3;
    WaterGun = 4;
    FlashGannon = 5;
    AquaTail = 6;
    skillStyle[Tackle] = 1;
    skillStyle[RainDance] = 0;
    skillStyle[Withdraw] = 0;
    skillStyle[WaterPulse] = 5;
    skillStyle[WaterGun] = 1;
    skillStyle[FlashGannon] = 1;
    skillStyle[AquaTail] = 3;
}

void SquirtleSkill::skillEffect(pokemon &A, pokemon &B, int skill){
    RoundOver C;
    if(skill == Tackle){
        B.setnowHp(0 - randomBetween(0.95,1.05)* getInjure(A,B,getAttRelate(NORMAL ,B)));
        qDebug()<<"HURT";
    }
    else if(skill == WaterGun){
        B.setnowHp(0 - randomBetween(0.85,1.25)* getInjure(A,B,getAttRelate(WATER ,B)));
        qDebug()<<"HURT";
    }
    else if(skill == Withdraw){
        A.setnowDefense(1.3 * A.getnowDefense());
        C.move = DEFENSE;
        C.count = 3;
        C.num = 1.3;
        A.continueBuff.push_back(C);
        A.setnowSp_Def(1.3 * A.getnowSp_Def());
        C.move = SPDEF;
        C.count = 3;
        C.num = 1.4;
        A.continueBuff.push_back(C);
    }
    else if(skill == WaterPulse){
        B.setnowHp(0 - randomBetween(0.75,1)* 0.4 * getInjure(A,B,getAttRelate(WATER ,B)));
        qDebug()<<"HURT";
        B.setnowSpeed(0.9 * B.getnowSpeed());
        C.move = SPEED;
        C.count = 4;
        C.num = 0.9;
        B.continueBuff.push_back(C);
        B.setnowSp_Atk(0.8 * B.getnowSp_Atk());
        C.move = SPATK;
        C.count = 4;
        C.num = 0.9;
        B.continueBuff.push_back(C);
    }
    else if(skill == RainDance){
        A.setnowAttack(1.1 * A.getnowAttack());
        C.move = ATTACK;
        C.count = 4;
        C.num = 1.1;
        B.continueBuff.push_back(C);
        A.setnowSp_Atk(1.1 * A.getnowSp_Atk());
        C.move = SPATK;
        C.count = 4;
        C.num = 1.1;
        B.continueBuff.push_back(C);
    }
    else if(skill == FlashGannon){
        B.setnowHp(0 - randomBetween(0.94,1.16)* 0.5 * getInjure(A,B,getAttRelate(WATER ,B)));
        qDebug()<<"HURT";
        B.setnowHp(0 - randomBetween(0.94,1.2)* 0.6 * getInjure(A,B,getAttRelate(WATER ,B)));
        qDebug()<<"HURT";
    }
    else if(skill == AquaTail){
        B.setnowHp(0 - randomBetween(0.94,1.16)* 0.5 * getInjure(A,B,getAttRelate(WATER ,B)));
        qDebug()<<"HURT";
    }
    else;
}

QString SquirtleSkill::returnSkillName(int skill){
    switch(skill){
    case 0:
        return "Tackle";
    case 1:
        return "RainDance";
    case 2:
        return "Withdraw";
    case 3:
        return "WaterPulse";
    case 4:
        return "WaterGun";
    case 5:
        return "FlashGannon";
    case 6:
        return "AquaTail";
    default:
        return "false";
    }
}

/*--------------------------------------------------------------*/

Bulbasaur::Bulbasaur(){
    skill = new Bulbasaurskill();
    setLevel(0);
    setlevelMax(10);
    setHp(4500);
    setAttack(4900);
    setDefense(4900);
    setSp_Atk(6500);
    setSp_Def(6500);
    setSpeed(4500);
    setcofHPGrow(249);
    setcofAttackGrow(168);
    setcofDefenseGrow(168);
    setcofSp_AtkGrow(186);
    setcofSp_DefGrow(186);
    setcofSpeedGrow(162);
    setValue(318);
    addAttitude(GRASS);
    addAttitude(POISON);
}

QString Bulbasaur::returnPokename(){
    return "Bulbasaur";
}

QString Bulbasaur::returnInitialname(){
    return "Bulbasaur";
}

pokeskill * Bulbasaur::skillInitial(){
    return skill;
}

Lvysaur::Lvysaur(){
    skill = new Bulbasaurskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1500);
    setAttack(getAttack() + 1300);
    setDefense(getDefense() + 1400);
    setSp_Atk(getSp_Atk() + 1500);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(264);
    setcofAttackGrow(183);
    setcofDefenseGrow(184);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(204);
    setcofSpeedGrow(180);
    setValue(405);
    skill->addrandomskill();
}

QString Lvysaur::returnPokename(){
    return "Lvysaur";
}

pokeskill * Lvysaur::skillInitial(){
    return skill;
}


Lvysaur::Lvysaur(int choose){
    skill = new Bulbasaurskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1500);
    setAttack(getAttack() + 1300);
    setDefense(getDefense() + 1400);
    setSp_Atk(getSp_Atk() + 1500);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(264);
    setcofAttackGrow(183);
    setcofDefenseGrow(184);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(204);
    setcofSpeedGrow(180);
    setValue(405);
    skill->addskill(choose);
}

Lvysaur::Lvysaur(int level,int skill1){
    skill = new Bulbasaurskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1500);
    setAttack(getAttack() + 1300);
    setDefense(getDefense() + 1400);
    setSp_Atk(getSp_Atk() + 1500);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(264);
    setcofAttackGrow(183);
    setcofDefenseGrow(184);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(204);
    setcofSpeedGrow(180);
    setValue(405);
    levelUP(level - 10);
    skill->deleteSkill();
    skill->addskill(skill1);
}

Venusaur::Venusaur(){
    skill = new Bulbasaurskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() + 2000);
    setcofHPGrow(284);
    setcofAttackGrow(207);
    setcofDefenseGrow(208);
    setcofSp_AtkGrow(228);
    setcofSp_DefGrow(228);
    setcofSpeedGrow(204);
    setValue(525);
    skill->addrandomskill();
}

Venusaur::Venusaur(pokemon *L){
    skill = new Bulbasaurskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() +2000);
    setcofHPGrow(284);
    setcofAttackGrow(207);
    setcofDefenseGrow(208);
    setcofSp_AtkGrow(228);
    setcofSp_DefGrow(228);
    setcofSpeedGrow(204);
    setValue(525);
    skill->deleteSkill();
    skill->addskill(L->skillInitial()->getFirstSkill());
    skill->addrandomskill();
}

pokeskill * Venusaur::skillInitial(){
    return skill;
}

Venusaur::Venusaur(int level,int skill1,int skill2){
    skill = new Bulbasaurskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() +2000);
    setcofHPGrow(284);
    setcofAttackGrow(207);
    setcofDefenseGrow(208);
    setcofSp_AtkGrow(228);
    setcofSp_DefGrow(228);
    setcofSpeedGrow(204);
    setValue(525);
    levelUP(level - 20);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
}

QString Venusaur::returnPokename(){
    return "Venusaur";
}


MegaVenusaur::MegaVenusaur(){
    skill = new Bulbasaurskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 1800);
    setDefense(getDefense() + 4000);
    setSp_Atk(getSp_Atk() + 2200);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(284);
    setcofAttackGrow(228);
    setcofDefenseGrow(256);
    setcofSp_AtkGrow(255);
    setcofSp_DefGrow(252);
    setcofSpeedGrow(204);
    setValue(625);
    skill->addrandomskill();
}

MegaVenusaur::MegaVenusaur(pokemon *V){
    skill = new Bulbasaurskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 1800);
    setDefense(getDefense() + 4000);
    setSp_Atk(getSp_Atk() + 2200);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(284);
    setcofAttackGrow(228);
    setcofDefenseGrow(256);
    setcofSp_AtkGrow(255);
    setcofSp_DefGrow(252);
    setcofSpeedGrow(204);
    setValue(625);
    skill->deleteSkill();
    skill->addskill(V->skillInitial()->getFirstSkill());
    skill->addskill(V->skillInitial()->getSecondSkill());
    skill->addrandomskill();
}

MegaVenusaur::MegaVenusaur(int level,int skill1,int skill2,int skill3){
    skill = new Bulbasaurskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 1800);
    setDefense(getDefense() + 4000);
    setSp_Atk(getSp_Atk() + 2200);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(284);
    setcofAttackGrow(228);
    setcofDefenseGrow(256);
    setcofSp_AtkGrow(255);
    setcofSp_DefGrow(252);
    setcofSpeedGrow(204);
    setValue(625);
    levelUP(level - 30);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
    skill->addskill(skill3);
}

QString MegaVenusaur::returnPokename(){
    return "MegaVenusaur";
}

pokeskill * MegaVenusaur::skillInitial(){
    return skill;
}

/*--------------------------------------------------------------*/

Charmander::Charmander(){
    skill = new Charmanderskill();
    setLevel(0);
    setlevelMax(10);
    setHp(3900);
    setAttack(5200);
    setDefense(4300);
    setSp_Atk(6000);
    setSp_Def(5000);
    setSpeed(6500);
    setcofHPGrow(243);
    setcofAttackGrow(171);
    setcofDefenseGrow(160);
    setcofSp_AtkGrow(180);
    setcofSp_DefGrow(168);
    setcofSpeedGrow(186);
    setValue(309);
    addAttitude(FIRE);
}

pokeskill * Charmander::skillInitial(){
    return skill;
}

QString Charmander::returnPokename(){
    return "Charmander";
}

QString Charmander::returnInitialname(){
    return "Charmander";
}

Charmeleon::Charmeleon(){
    skill = new Charmanderskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1900);
    setAttack(getAttack() + 1200);
    setDefense(getDefense() + 1500);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(262);
    setcofAttackGrow(185);
    setcofDefenseGrow(178);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(186);
    setcofSpeedGrow(204);
    setValue(405);
    skill->addrandomskill();
}

pokeskill * Charmeleon::skillInitial(){
    return skill;
}

Charmeleon::Charmeleon(int choose){
    skill = new Charmanderskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1900);
    setAttack(getAttack() + 1200);
    setDefense(getDefense() + 1500);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(262);
    setcofAttackGrow(185);
    setcofDefenseGrow(178);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(186);
    setcofSpeedGrow(204);
    setValue(405);
    skill->addskill(choose);
}

Charmeleon::Charmeleon(int level,int skill1){
    skill = new Charmanderskill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1900);
    setAttack(getAttack() + 1200);
    setDefense(getDefense() + 1500);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 1500);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(262);
    setcofAttackGrow(185);
    setcofDefenseGrow(178);
    setcofSp_AtkGrow(204);
    setcofSp_DefGrow(186);
    setcofSpeedGrow(204);
    setValue(405);
    levelUP(level - 10);
    skill->deleteSkill();
    skill->addskill(skill1);
}

QString Charmeleon::returnPokename(){
    return "Charmeleon";
}

Charizard::Charizard(){
    skill = new Charmanderskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2900);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() +2000);
    setcofHPGrow(282);
    setcofAttackGrow(209);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(239);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(534);
    skill->addrandomskill();
    addAttitude(FLYING);
}

Charizard::Charizard(pokemon *C){
    skill = new Charmanderskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2900);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() +2000);
    setcofHPGrow(282);
    setcofAttackGrow(209);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(239);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(534);
    skill->deleteSkill();
    skill->addskill(C->skillInitial()->getFirstSkill());
    skill->addrandomskill();
    addAttitude(FLYING);
}

Charizard::Charizard(int level,int skill1,int skill2){
    skill = new Charmanderskill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2900);
    setSp_Def(getSp_Def() + 2000);
    setSpeed(getSpeed() +2000);
    setcofHPGrow(282);
    setcofAttackGrow(209);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(239);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(534);
    addAttitude(FLYING);
    levelUP(level - 20);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
}

pokeskill * Charizard::skillInitial(){
    return skill;
}

QString Charizard::returnPokename(){
    return "Charizard";
}

MegaCharizardX::MegaCharizardX(){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 4600);
    setDefense(getDefense() + 3300);
    setSp_Atk(getSp_Atk() + 2100);
    setSp_Def(getSp_Def() + 0);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(264);
    setcofDefenseGrow(242);
    setcofSp_AtkGrow(264);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(634);
    skill->addrandomskill();
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
}

MegaCharizardX::MegaCharizardX(pokemon *C){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 4600);
    setDefense(getDefense() + 3300);
    setSp_Atk(getSp_Atk() + 2100);
    setSp_Def(getSp_Def() + 0);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(264);
    setcofDefenseGrow(242);
    setcofSp_AtkGrow(264);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(634);
    skill->deleteSkill();
    skill->addskill(C->skillInitial()->getFirstSkill());
    skill->addskill(C->skillInitial()->getSecondSkill());
    skill->addrandomskill();
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
}

MegaCharizardX::MegaCharizardX(int level,int skill1,int skill2,int skill3){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 4600);
    setDefense(getDefense() + 3300);
    setSp_Atk(getSp_Atk() + 2100);
    setSp_Def(getSp_Def() + 0);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(264);
    setcofDefenseGrow(242);
    setcofSp_AtkGrow(264);
    setcofSp_DefGrow(210);
    setcofSpeedGrow(228);
    setValue(634);
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
    levelUP(level - 30);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
    skill->addskill(skill3);
}

QString MegaCharizardX::returnPokename(){
    return "MegaCharizardX";
}

pokeskill * MegaCharizardX::skillInitial(){
    return skill;
}

MegaCharizardY::MegaCharizardY(){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 0);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 3000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(233);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(299);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(228);
    setValue(634);
    skill->addrandomskill();
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
}

MegaCharizardY::MegaCharizardY(pokemon *C){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 0);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 3000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(233);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(299);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(228);
    setValue(634);
    skill->deleteSkill();
    skill->addskill(C->skillInitial()->getFirstSkill());
    skill->addskill(C->skillInitial()->getSecondSkill());
    skill->addrandomskill();
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
}

MegaCharizardY::MegaCharizardY(int level,int skill1,int skill2,int skill3){
    skill = new Charmanderskill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 0);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 3000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(282);
    setcofAttackGrow(233);
    setcofDefenseGrow(202);
    setcofSp_AtkGrow(299);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(228);
    setValue(634);
    deleteAttitude();
    addAttitude(FIRE);
    addAttitude(DRAGON);
    levelUP(level - 30);
    skill->addskill(skill1);
    skill->addskill(skill2);
    skill->addskill(skill3);
}

QString MegaCharizardY::returnPokename(){
    return "MegaCharizardY";
}

pokeskill * MegaCharizardY::skillInitial(){
    return skill;
}

/*--------------------------------------------------------------*/

Squirtle::Squirtle(){
     skill = new SquirtleSkill();
     setLevel(0);
     setlevelMax(10);
     setHp(4400);
     setAttack(4800);
     setDefense(6500);
     setSp_Atk(5000);
     setSp_Def(6400);
     setSpeed(4300);
     setcofHPGrow(248);
     setcofAttackGrow(166);
     setcofDefenseGrow(186);
     setcofSp_AtkGrow(168);
     setcofSp_DefGrow(185);
     setcofSpeedGrow(160);
     setValue(314);
     addAttitude(WATER);
}

QString Squirtle::returnPokename(){
    return "Squirtle";
}

QString Squirtle::returnInitialname(){
    return "Squirtle";
}

pokeskill * Squirtle::skillInitial(){
    return skill;
}

Wartortle::Wartortle(){
     skill = new SquirtleSkill();
     setlevelMax(20);
     levelUP(10);
     setHp(getHP() + 1500);
     setAttack(getAttack() + 1500);
     setDefense(getDefense() + 1500);
     setSp_Atk(getSp_Atk() + 1500);
     setSp_Def(getSp_Def() + 1600);
     setSpeed(getSpeed() +1500);
     setcofHPGrow(263);
     setcofAttackGrow(184);
     setcofDefenseGrow(204);
     setcofSp_AtkGrow(186);
     setcofSp_DefGrow(204);
     setcofSpeedGrow(178);
     setValue(405);
     skill->addrandomskill();
}

Wartortle::Wartortle(int choose){
     skill = new SquirtleSkill();
     setlevelMax(20);
     levelUP(10);
     setHp(getHP() + 1500);
     setAttack(getAttack() + 1500);
     setDefense(getDefense() + 1500);
     setSp_Atk(getSp_Atk() + 1500);
     setSp_Def(getSp_Def() + 1600);
     setSpeed(getSpeed() +1500);
     setcofHPGrow(263);
     setcofAttackGrow(184);
     setcofDefenseGrow(204);
     setcofSp_AtkGrow(186);
     setcofSp_DefGrow(204);
     setcofSpeedGrow(178);
     setValue(405);
     skill->addskill(choose);
}

Wartortle::Wartortle(int level,int skill1){
    skill = new SquirtleSkill();
    setlevelMax(20);
    levelUP(10);
    setHp(getHP() + 1500);
    setAttack(getAttack() + 1500);
    setDefense(getDefense() + 1500);
    setSp_Atk(getSp_Atk() + 1500);
    setSp_Def(getSp_Def() + 1600);
    setSpeed(getSpeed() +1500);
    setcofHPGrow(263);
    setcofAttackGrow(184);
    setcofDefenseGrow(204);
    setcofSp_AtkGrow(186);
    setcofSp_DefGrow(204);
    setcofSpeedGrow(178);
    setValue(405);
    levelUP(level - 10);
    skill->addskill(skill1);
}

QString Wartortle::returnPokename(){
    return "Wartortle";
}

pokeskill * Wartortle::skillInitial(){
    return skill;
}

Blastoise::Blastoise(){
    skill = new SquirtleSkill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2500);
    setSpeed(getSpeed() + 2000);
    setcofHPGrow(283);
    setcofAttackGrow(208);
    setcofDefenseGrow(228);
    setcofSp_AtkGrow(210);
    setcofSp_DefGrow(234);
    setcofSpeedGrow(202);
    setValue(530);
    skill->addrandomskill();
}

Blastoise::Blastoise(pokemon *W){
    skill = new SquirtleSkill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2500);
    setSpeed(getSpeed() + 2000);
    setcofHPGrow(283);
    setcofAttackGrow(208);
    setcofDefenseGrow(228);
    setcofSp_AtkGrow(210);
    setcofSp_DefGrow(234);
    setcofSpeedGrow(202);
    setValue(530);
    skill->deleteSkill();
    skill->addskill(W->skillInitial()->getFirstSkill());
    skill->addrandomskill();
}

pokeskill * Blastoise::skillInitial(){
    return skill;
}

Blastoise::Blastoise(int level,int skill1,int skill2){
    skill = new SquirtleSkill();
    setlevelMax(30);
    levelUP(10);
    setHp(getHP() + 2000);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 2000);
    setSp_Def(getSp_Def() + 2500);
    setSpeed(getSpeed() + 2000);
    setcofHPGrow(283);
    setcofAttackGrow(208);
    setcofDefenseGrow(228);
    setcofSp_AtkGrow(210);
    setcofSp_DefGrow(234);
    setcofSpeedGrow(202);
    setValue(530);
    levelUP(level - 20);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
}

QString Blastoise::returnPokename(){
    return "Blastoise";
}

MegaBlastoise::MegaBlastoise(){
    skill = new SquirtleSkill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 1000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(283);
    setcofAttackGrow(232);
    setcofDefenseGrow(252);
    setcofSp_AtkGrow(270);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(202);
    setValue(630);
    skill->addrandomskill();
}

MegaBlastoise::MegaBlastoise(pokemon *B){
    skill = new SquirtleSkill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 1000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(283);
    setcofAttackGrow(232);
    setcofDefenseGrow(252);
    setcofSp_AtkGrow(270);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(202);
    setValue(630);
    skill->deleteSkill();
    skill->addskill(B->skillInitial()->getFirstSkill());
    skill->addskill(B->skillInitial()->getSecondSkill());
    skill->addrandomskill();
}

MegaBlastoise::MegaBlastoise(int level,int skill1,int skill2,int skill3){
    skill = new SquirtleSkill();
    setlevelMax(40);
    levelUP(10);
    setHp(getHP() + 0);
    setAttack(getAttack() + 2000);
    setDefense(getDefense() + 2000);
    setSp_Atk(getSp_Atk() + 5000);
    setSp_Def(getSp_Def() + 1000);
    setSpeed(getSpeed() + 0);
    setcofHPGrow(283);
    setcofAttackGrow(232);
    setcofDefenseGrow(252);
    setcofSp_AtkGrow(270);
    setcofSp_DefGrow(246);
    setcofSpeedGrow(202);
    setValue(630);
    levelUP(level - 30);
    skill->deleteSkill();
    skill->addskill(skill1);
    skill->addskill(skill2);
    skill->addskill(skill3);
}

QString MegaBlastoise::returnPokename(){
    return "MegaBlastoise";
}

pokeskill * MegaBlastoise::skillInitial(){
    return skill;
}

void caculateBuff(pokemon A){
    RoundOver C1;
    vector<RoundOver> Abuff;
    A.setnowAttack(A.getAttack());
    A.setnowDefense(A.getDefense());
    A.setnowSpeed(A.getSpeed());
    A.setnowSp_Atk(A.getSp_Atk());
    A.setnowSp_Def(A.getSp_Def());
/*    B.setnowAttack(A.getAttack());
    B.setnowDefense(A.getDefense());
    B.setnowSpeed(A.getSpeed());
    B.setnowSp_Atk(A.getSp_Atk());
    B.setnowSp_Def(A.getSp_Def());*/
    while(!A.continueBuff.empty()){
        C1.count = A.continueBuff[A.continueBuff.size() - 1].count;
        C1.move = A.continueBuff.back().move;
        C1.num = A.continueBuff.back().num;
        A.continueBuff.pop_back();
        while(C1.count < 0 && !A.continueBuff.empty()){
            C1.count = A.continueBuff.back().count;
            C1.move = A.continueBuff.back().move;
            C1.num = A.continueBuff.back().num;
            A.continueBuff.pop_back();
        }
        switch (C1.move) {
        case LIFE:
            A.setnowHp(A.getnowHP() + C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        case ATTACK:
            A.setnowAttack(A.getnowAttack() * C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        case DEFENSE:
            A.setnowDefense(A.getnowDefense() * C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        case SPATK:
            A.setnowSp_Atk(A.getnowSp_Atk() * C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        case SPDEF:
            A.setnowSp_Def(A.getnowDefense() * C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        case SPEED:
            A.setnowSpeed(A.getnowSpeed() * C1.num);
            C1.count--;
            Abuff.push_back(C1);
            break;
        default:
            break;
        }
    }
    A.continueBuff.swap(Abuff);
  /*  while(B.continueBuff.empty()){
        C2 = B.continueBuff.pop_back();
        while(C2.count == 0 && B.continueBuff.empty()){
            C2 = B.continueBuff.pop_back();
        }
        switch (C2.move) {
        case LIFE:
            B.setnowHp(B.getnowHP() + C2.num);
            C2.count--;
            Bbuff.push_back(C2);
            break;
        case ATTACK:
            B.setnowAttack(B.getnowAttack() * C2.num);
            C2.count--;
            Bbuff.push_back(C2);
        case DEFENSE:
            B.setnowDefense(B.getnowDefense() * C2.num);
            C2.count--;
            Bbuff.push_back(C2);
        case SPATK:
            B.setnowSp_Atk(B.getnowSp_Atk() * C2.num);
            C2.count--;
            Bbuff.push_back(C2);
        case SPDEF:
            B.setnowSp_Def(B.getnowDefense() * C2.num);
            C2.count--;
            Bbuff.push_back(C2);
        case SPEED:
            B.setnowSpeed(B.getnowSpeed() * C2.num);
            C2.count--;
            Bbuff.push_back(C2);
        default:
            break;
        }
    }*/
}

void returnPokemon(pokemon *a,QString pokename,int pokelevel,int pokeexp,int skill1,int skill2,int skill3){
    if(pokename == "Bulbasaur"){
        a = new Bulbasaur();
        a->levelUP(pokelevel);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Lvysaur"){
        a = new Lvysaur(pokelevel,skill1);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Venusaur"){
        a = new Venusaur(pokelevel,skill1,skill2);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "MegaVenusaur"){
        a = new MegaVenusaur(pokelevel,skill1,skill2,skill3);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Charmander"){
        a = new Charmander();
        a->levelUP(pokelevel);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Charmeleon"){
        a = new Charmeleon(pokelevel,skill1);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Charizard"){
        a = new Charizard(pokelevel,skill1,skill2);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "MegaCharizardX"){
        a = new MegaCharizardX(pokelevel,skill1,skill2,skill3);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "MegaCharizardY"){
        a = new MegaCharizardY(pokelevel,skill1,skill2,skill3);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Squirtle"){
        a = new Squirtle();
        a->levelUP(pokelevel);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Wartortle"){
        a = new Wartortle(pokelevel,skill1);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "Blastoise"){
        a = new Blastoise(pokelevel,skill1,skill2);
        a->setnowExp(pokeexp);
    }
    else if(pokename == "MegaBlastoise"){
        a = new MegaBlastoise(pokelevel,skill1,skill2,skill3);
        a->setnowExp(pokeexp);
    }
}

void changePokemon(pokemon *a){
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()*10 + time.second()*1000);
    if(a->returnPokename() == "Bulbasaur"){
        a = new Lvysaur();
    }
    else if(a->returnPokename() == "Lvysaur"){
        a = new Venusaur(a);
    }
    else if(a->returnPokename() == "Venusaur"){
        a = new MegaVenusaur(a);
    }
    else if(a->returnPokename() == "Charmander"){
        a = new Charmeleon();
    }
    else if(a->returnPokename() == "Charmeleon"){
        a = new Charizard(a);
    }
    else if(a->returnPokename() == "Charizard"){
        if(qrand()%2 == 0)
            a = new MegaCharizardX(a);
        else
            a = new MegaCharizardY(a);
    }
    else if(a->returnPokename() == "Squirtle"){
        a = new Wartortle();
    }
    else if(a->returnPokename() == "Wartortle"){
        a = new Blastoise(a);
    }
    else if(a->returnPokename() == "Blastoise"){
        a = new MegaBlastoise(a);
    }
}
