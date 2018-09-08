#ifndef POKEMON_H
#define POKEMON_H

#include<vector>
#include<tuple>
#include <QString>

class pokeskill;

#define NORMAL 0

#define FIRE 1

#define WATER 2

#define GRASS 3

#define ELECTRIC 4

#define ICE 5

#define FIGHTING 6

#define POISON 7

#define GROUND 8

#define FLYING 9

#define PSYCHIC 10

#define BUG 11

#define ROCK 12

#define GHOST 13

#define DRAGON 14

#define DARK 15

#define STEEL 16

#define LIFE 0

#define ATTACK 1

#define DEFENSE 2

#define SPATK 3

#define SPDEF 4

#define SPEED 5

#define NUMBER 0

#define COUNT 1

extern int AttituRelate[17][17];


using namespace std;

typedef struct roundover{
    int move;
    float num;
    int count;
}RoundOver;

class pokemon
{
public:

    pokemon();

    int getHP();

    int getnowHP();

    int getAttack();

    int getnowAttack();

    int getDefense();

    int getnowDefense();

    int getSp_Atk();

    int getnowSp_Atk();

    int getSp_Def();

    int getnowSp_Def();

    int getSpeed();

    int getnowSpeed();

    int getValue();

    int getLevel();

    int getlevelMax();

    int getExperience();

    int getnowExperience();

    vector<RoundOver> continueBuff;

    vector<int> getAttitude();

    void setHp(int hp);

    void setAttack(int attack);

    void setDefense(int defense);

    void setSp_Atk(int spatk);

    void setSp_Def(int spdef);

    void setSpeed(int speed);

    void setValue(int value);

    void setLevel(int level);

    void setlevelMax(int num);

    void setExperience();

    void setnowHp(int add);

    void setnowAttack(int nowattack);

    void setnowDefense(int nowdefense);

    void setnowSp_Atk(int spatk);

    void setnowSpeed(int nowspeed);

    void setnowSp_Def(int nowspdef);

    void setnowExp(int nowExp);

    void addAttitude(int att);

    void deleteAttitude();

    void levelUPHP(int number);

    void levelUPHP(int number ,int level);

    void levelUPAttack(int number);

    void levelUPAttack(int number, int level);

    void levelUPDefense(int number);

    void levelUPDefense(int number ,int level);

    void levelUPSp_Atk(int number);

    void levelUPSp_Atk(int number ,int level);

    void levelUPSp_Def(int number);

    void levelUPSp_Def(int number ,int level);

    void levelUPSpeed(int number);

    void levelUPSpeed(int number ,int level);

    int getcofHPGrow();

    int getcofAttackGrow();

    int getcofDefenseGrow();

    int getcofSp_AtkGrow();

    int getcofSp_DefGrow();

    int getcofSpeedGrow();

    void setcofHPGrow(int cof);

    void setcofAttackGrow(int cof);

    void setcofDefenseGrow(int cof);

    void setcofSp_AtkGrow(int cof);

    void setcofSp_DefGrow(int cof);

    void setcofSpeedGrow(int cof);

    void expUP(int number);

    void levelUP();

    void levelUP(int num);

    virtual pokeskill * skillInitial();

    virtual QString returnPokename();

    virtual QString returnInitialname();


private:

    int HP;

    int nowHP;

    int Attack;

    int nowAttack;

    int Defense;

    int nowDefense;

    int Sp_Atk;

    int nowSp_Atk;

    int Sp_Def;

    int nowSp_Def;

    int Speed;

    int nowSpeed;

    int Value;

    int nowValue;

    int Level;

    int levelMax;

    int Experience;

    int nowExperience;

    int cofHPGrow;

    int cofAttackGrow;

    int cofDefenseGrow;

    int cofSp_AtkGrow;

    int cofSp_DefGrow;

    int cofSpeedGrow;

    vector<int> Attitude;

    pokeskill *skill;
};

/*--------------------------------------------------------------*/

class pokeskill
{
public:

   pokeskill();

   int getFirstSkill();

   int getSecondSkill();

   int getThirdSkill();

   int randomSkill();

   int releaseSkill(int skill, int peopleNum);

   int returnRandomskill();

   bool nofullskill();

   bool addskill(int skill);

   bool addrandomskill();

   int getInjure(pokemon A,pokemon B,int AttRa);

   int getAttRelate(int attitude1, pokemon B);

   float randomBetween(float a, float b);

   int ranBetween(int a,int b);

   int skillStyle[7];

   const int maxskill = 6;

   int keepSkill[4];

   void deleteSkill();

   virtual void skillEffect(pokemon *A , pokemon *B, int skill);

   virtual QString returnSkillName(int skill);
};

class Bulbasaurskill : public pokeskill{
public:

    Bulbasaurskill();

    virtual void skillEffect(pokemon *A , pokemon *B, int skill);

    virtual QString returnSkillName(int skill);

    int Tackle;

    int Synthesis;

    int Growth;

    int LeechSeed;

    int PoisonPowder;

    int RazorLeaf;

    int SeedBomb;

};

class Charmanderskill : public pokeskill{
public:

    Charmanderskill();

    virtual void skillEffect(pokemon *A , pokemon *B, int skill);

    virtual QString returnSkillName(int skill);

    int Scratch;

    int Smokescreen;

    int DragonRage;

    int Ember;

    int Flameburst;

    int Heatwave;

    int FlareBlitz;

};

class SquirtleSkill : public pokeskill{
public:

    SquirtleSkill();

    virtual void skillEffect(pokemon *A, pokemon *B, int skill);

    virtual QString returnSkillName(int skill);

    int Tackle;

    int RainDance;

    int Withdraw;

    int WaterPulse;

    int WaterGun;

    int FlashGannon;

    int AquaTail;

};

/*--------------------------------------------------------------*/

class Bulbasaur : public pokemon{
public:

    Bulbasaur();

    virtual pokeskill * skillInitial();

    virtual QString returnPokename();

    virtual QString returnInitialname();

private:
    Bulbasaurskill *skill;

};

class Lvysaur : public Bulbasaur{
public:

    Lvysaur();

    Lvysaur(int choose);

    Lvysaur(int level,int skill1);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
    Bulbasaurskill *skill;

};

class Venusaur : public Lvysaur{
public:

    Venusaur();

    Venusaur(pokemon *L);

    Venusaur(int level,int skill1,int skill2);

    virtual pokeskill * skillInitial();

    virtual QString returnPokename();

private:
    Bulbasaurskill *skill;

};

class MegaVenusaur : public Venusaur{
public:

    MegaVenusaur();

    MegaVenusaur(pokemon *V);

    MegaVenusaur(int level,int skill1,int skill2,int skill3);

    virtual pokeskill * skillInitial();

    virtual QString returnPokename();

private:
    Bulbasaurskill *skill;

};

/*--------------------------------------------------------------*/

class Charmander : public pokemon{
public:

    Charmander();

    virtual QString returnPokename();

    virtual QString returnInitialname();

    virtual pokeskill * skillInitial();

private:
    Charmanderskill *skill;
};

class Charmeleon : public Charmander{
public:

    Charmeleon();

    Charmeleon(int choose);

    Charmeleon(int level,int skill1);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
    Charmanderskill *skill;
};

class Charizard : public Charmeleon{
public:

    Charizard();

    Charizard(pokemon *C);

    Charizard(int level,int skill1,int skill2);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
    Charmanderskill *skill;
};

class MegaCharizardX : public Charizard{
public:

    MegaCharizardX();

    MegaCharizardX(pokemon *C);

    MegaCharizardX(int level,int skill1,int skill2,int skill3);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
    Charmanderskill *skill;
};

class MegaCharizardY : public Charizard{
public:

    MegaCharizardY();

    MegaCharizardY(pokemon *C);

    MegaCharizardY(int level,int skill1,int skill2,int skill3);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
    Charmanderskill *skill;
};

/*--------------------------------------------------------------*/

class  Squirtle : public pokemon{
public:

    Squirtle();

    virtual QString returnPokename();

    virtual QString returnInitialname();

    virtual pokeskill * skillInitial();

private:
     SquirtleSkill * skill;
};

class Wartortle : public Squirtle{
public:

    Wartortle();

    Wartortle(int choose);

    Wartortle(int level,int skill1);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
     SquirtleSkill * skill;
};

class Blastoise : public Wartortle{
public:

    Blastoise();

    Blastoise(pokemon *W);

    Blastoise(int level,int skill1,int skill2);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
     SquirtleSkill * skill;
};

class MegaBlastoise : public Blastoise{
public:

    MegaBlastoise();

    MegaBlastoise(pokemon *B);

    MegaBlastoise(int level,int skill1,int skill2,int skill3);

    virtual QString returnPokename();

    virtual pokeskill * skillInitial();

private:
     SquirtleSkill * skill;
};

/*--------------------------------------------------------------*/

void caculateBuff(pokemon *A);

void returnPokemon(pokemon *a,QString pokename,int pokelevel,int pokeexp,int skill1,int skill2,int skill3);

void changePokemon(pokemon *a);
#endif // POKEMON_H
