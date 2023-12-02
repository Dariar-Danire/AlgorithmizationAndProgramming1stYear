#include <vector>

class OSUpdater : public IRunnable{
    void run() {
        std::cout << "OSUpdater";
    }
};

class Alarm : public IRunnable{
    void run() {
        std::cout << "Alarm";
    }
};

class ActivityChecker : public IRunnable {
    void run() {
        std::cout << "ActivityChecker";
    }
};

struct Event {
    Time time_mark;
    IRunnable* IR;
};

bool operator==(const Event& ev1, const Event& ev2) {
    return ev1.IR == ev2.IR && ev1.time_mark == ev2.time_mark;
}

std::vector<Event> eventsList;

std::string formatTime(Time time) {
    std::string hoursR = std::to_string(time.hours);
    std::string minutesR = std::to_string(time.minutes);
    std::string secondsR = std::to_string(time.seconds);

    if (time.hours < 10) {
        hoursR = '0' + hoursR;
    }
    if (time.minutes < 10) {
        minutesR = '0' + minutesR;
    }
    if (time.seconds < 10) {
        secondsR = '0' + secondsR;
    }

    return hoursR + ':' + minutesR + ':' + secondsR;
}

class Clock : public IClock, public IRunnable {

    Event findMinTime() {
        Time time{ 59, 59, 59 };
        for (Event& evnt : eventsList) {
            if (evnt.time_mark < time) {
                return evnt;
            }
        }
    }

public: 
    void run() {
        while (next());
    }

    void add(IRunnable* client, Time time) {
        Event evnt {time, client};
        eventsList.push_back(evnt);
    }
    
    bool next() {
        if (eventsList.empty()) {
            return false;
        }

        Event evnt = findMinTime();

        std::string hoursR = std::to_string(evnt.time_mark.hours);

        std::cout << formatTime(evnt.time_mark) << ' ';
        evnt.IR->run();
        std::cout << std::endl;

        // Удалить событие из списка
        for (std::vector<Event>::iterator i = eventsList.begin(); i != eventsList.end(); ++i) {
            if (*i == evnt) {
                eventsList.erase(i);
                break;
            }
        }

        return true;
    }
};
