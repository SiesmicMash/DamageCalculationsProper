#ifdef AI_h
#define AI_H

class Character;
class Enemy;

class AI {
public:
	virtual void makeDecisison(Character& character, Enemy& enemy) = 0;
	virtual ~AI() = default;
};

#endif