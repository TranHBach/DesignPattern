#include <iostream>

// create interfaces
class FlyBehavior {
public:
    virtual void fly() = 0;
};

class QuackBehavior {
public:
    virtual void quack() = 0;
};

//super class
class Duck {
protected:
    QuackBehavior* quackBehavior;
    FlyBehavior* flyBehavior;
public:
    Duck() : quackBehavior(nullptr), flyBehavior(nullptr) {}
    
    void performQuack() {
        quackBehavior->quack();
    }

    virtual void display() = 0;

    void performFly() {
        flyBehavior->fly();
    }

    void swim() {
        std::cout << "All ducks swim." << std::endl;
    }

    void setFlyBehavior(FlyBehavior* newBehavior) {
        flyBehavior = newBehavior;
    }

    void setQuackBehavior(QuackBehavior* newBehavior) {
        quackBehavior = newBehavior;
    }
};

class Quack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Quacks" << std::endl;
    }
};

class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I'm flying" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I'm not flying" << std::endl;
    }
};

class FlyWithRockets : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I'm flying with rockets" << std::endl;
    }
};

//duck types
class MallardDuck : public Duck {
public:
    MallardDuck() {
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings();
    }

    void display() override {
        std::cout << "I'm a Mallard Duck" << std::endl;
    }
};


class ModelDuck : public Duck {
public:
    ModelDuck() {
        flyBehavior = new FlyNoWay();
        quackBehavior = new Quack();
    }

    void display() override {
        std::cout << "I'm a model duck" << std::endl;
    }
};

class DuckCall {
private:
    QuackBehavior* quackBehavior;
    FlyBehavior* flyBehavior;

public:
    DuckCall() {
        quackBehavior = new Quack();
        flyBehavior = new FlyNoWay();
    }

    void display() {
        std::cout << "Not a real duck" << std::endl;
        quackBehavior->quack();
    }
};

int main() {
    Duck* mallardDuck = new MallardDuck();
    mallardDuck->display();
    mallardDuck->performFly();
    mallardDuck->performQuack();
    Duck* modelDuck = new ModelDuck();
    modelDuck->display();
    modelDuck->setFlyBehavior(new FlyWithRockets());
    modelDuck->performFly();
    DuckCall* duckCall = new DuckCall();
    duckCall->display();
    return 0;
}
