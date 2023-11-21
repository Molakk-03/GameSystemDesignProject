#include "Animals.h"

// 절댓값을 구하는 간단한 매크로
#define myabs(x) ((x) < 0 ? -(x) : (x))

// 토끼 클래스 
Rabbit::Rabbit(unsigned int iTeam) : Animal(2, 2, Animal::Rabbit, iTeam){
	// 코드 없음 
}
bool Rabbit::Move(int ax, int ay, int bx, int by) const{
	// x축 방향으로 이동 
	if((ay == by) && (myabs(ax - bx) == 2)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if((ax == bx) && (myabs(ay - by) == 2)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if((myabs(ax - bx) == 2) && (myabs(ay - by) == 2)) return Animal::Move(ax, ay, bx, by);
}
bool Rabbit::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 2) || (myabs(ay - by) <= 2)){
		if(((myabs(ax - bx) == 1) && (myabs(ay - by) == 2)) || ((myabs(ay - by) == 1) && (myabs(ax - bx) == 2))){
			return false;
		}
		return true;
	}

	return false;
}

// 돼지 클래스 
Pig::Pig(unsigned int iTeam) : Animal(3, 2, Animal::Pig, iTeam){
	this->ability_range = 5;
}
bool Pig::Move(int ax, int ay, int bx, int by) const{
	// x축 방향으로 이동 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Pig::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
// if((turn % 3)== 0) Pig::own_ability(ability_range);
void Pig::own_ability(int ability_range){
	//3의 배수 턴마다 자신을 중심으로 5*5 안에 있는 모든 말(적의 말 포함)에게 체력 +1 => change(1, 0) 이용하기 
}

// 하마 클래스 
Hippo::Hippo(unsigned int iTeam) : Animal(4, 3, Animal::Hippo, iTeam){
	// 코드 없음 
}
bool Hippo::Move(int ax, int ay, int bx, int by) const{
	// x축 방향으로 이동 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Hippo::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
void Hippo::own_ability(bool enemy_survive){
	//만약 공격한 상대의 hp가 0이하가 되어 survive가 false가 되면 공격력+1, 체력+1 
	if(!enemy_survive) change(1, 1); 
}

// 코끼리 클래스
Elephant::Elephant(unsigned int iTeam) : Animal(4, 4, Animal::Elephant, iTeam){
	this->ability_range = 3;
}
bool Elephant::Move(int ax, int ay, int bx, int by) const{
	// x축 방향으로 이동 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Elephant::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
/* Attack함수의 리턴값이 true이면 코끼리 말이 공격한 것이므로
   own_ability함수 실행 */ 
void Elephant::own_ability(int ability_range){
	//공격 시 자신을 중심으로 3*3 안에 있는 모든 말(아군 말 포함) 체력-1
}



Cow::Cow(unsigned int iTeam) : Animal(3, 2, Animal::Cow, iTeam) {
	this->ability_range = 5;
}
bool Cow::Move(int ax, int ay, int bx, int by) const {
	// x축 방향으로 이동 
	if ((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if ((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if ((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Cow::Attack(int ax, int ay, int bx, int by) const {
	if ((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;

	return false;
}
// if((turn % 3)== 0) Pig::own_ability(ability_range);
void Cow::own_ability(int ability_range) {
	//3의 배수 턴마다 자신을 중심으로 5*5 안에 있는 모든 말(적의 말 포함)에게 체력 +1 => change(1, 0) 이용하기 
}

Duck::Duck(unsigned int iTeam) : Animal(3, 2, Animal::Duck, iTeam) {
	this->ability_range = 5;
}
bool Duck::Move(int ax, int ay, int bx, int by) const {
	// x축 방향으로 이동 
	if ((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if ((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if ((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Duck::Attack(int ax, int ay, int bx, int by) const {
	if ((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;

	return false;
}
// if((turn % 3)== 0) Pig::own_ability(ability_range);
void Duck::own_ability(int ability_range) {
	//3의 배수 턴마다 자신을 중심으로 5*5 안에 있는 모든 말(적의 말 포함)에게 체력 +1 => change(1, 0) 이용하기 
}

Frog::Frog(unsigned int iTeam) : Animal(3, 2, Animal::Frog, iTeam) {
	this->ability_range = 5;
}
bool Frog::Move(int ax, int ay, int bx, int by) const {
	// x축 방향으로 이동 
	if ((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y축 방향으로 이동 
	if ((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// 대각선 방향으로 이동 
	if ((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Frog::Attack(int ax, int ay, int bx, int by) const {
	if ((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;

	return false;
}
// if((turn % 3)== 0) Pig::own_ability(ability_range);
void Frog::own_ability(int ability_range) {
	//3의 배수 턴마다 자신을 중심으로 5*5 안에 있는 모든 말(적의 말 포함)에게 체력 +1 => change(1, 0) 이용하기 
}