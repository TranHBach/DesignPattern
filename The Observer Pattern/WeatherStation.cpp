#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject
{
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyObserver() = 0;
};

class WeatherData : public Subject
{
private:
    vector<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    WeatherData()
    {
    }

    void registerObserver(Observer *o)
    {
        observers.push_back(o);
    }

    void removeObserver(Observer *o)
    {
        vector<Observer *>::iterator it;
        it = find(observers.begin(), observers.end(), o);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    void notifyObserver()
    {
        for (int i = 0; i < observers.size(); i++)
        {
            observers[i]->update(temperature, humidity, pressure);
        }
    }

    void measurementsChange()
    {
        notifyObserver();
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChange();
    }
};

class DisplayElement
{
public:
    virtual void display() = 0;
};

class CurrentConditionDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    Subject *weatherData;

public:
    CurrentConditionDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display()
    {
        cout << "Current temperature: " << temperature << "\nCurrent humidity: " << humidity << endl;
    }
};

int main()
{
    WeatherData *weatherData = new WeatherData();
    CurrentConditionDisplay *currentDisplay = new CurrentConditionDisplay(weatherData);
    weatherData->setMeasurements(82, 65, 30.4f);
    weatherData->setMeasurements(78, 70, 29.2f);
    weatherData->setMeasurements(80, 90, 29.2f);
}