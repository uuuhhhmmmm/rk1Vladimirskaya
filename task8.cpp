#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>
#include <vector>
#include <windows.h>


struct Student {
    char* name;
    int age;
    char* ID;
};

struct Mark {
    char subj[100];
    int id_subj;
    vector<int> marks_list;
    float averMark;

    Mark(const char* _subj) {
        memset(subj, 0, 100);
        memcpy(subj, _subj, strlen(_subj));

    }
    Mark(const char* _subj, int _idSubj) {
        memset(subj, 0, 100);
        memcpy(subj, _subj, strlen(_subj));
        id_subj = _idSubj;
    }
    ~Mark() {
    
    }

};


class Student1 {
private:
    Student* info;
    list<Mark*> listSubjMark;
    list<Mark*>::iterator lookForSub(const char* subjName);

public:

    Student1(const char* new_name, const int new _age, const char* new_numTicket) {
        info = new Student();
        info->name = (char*)new_name;
        info->age = new_age;
        info->ID = (char*)new_numTicket;


    }
    ~Student1()
    {
        delete info;
    }


    void addSubject(const char* subjName, int idSubj = 0) {

        for (list<Mark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            if (strcmp((*it)->subj, subjName) == 0)
            {
                (*it)->id_subj = idSubj;
                return;
            }
        }
        listSubjMark.push_back(new Mark(subjName, idSubj));

    }

    int addMarkToSubj(const char* subjName, int mark) {
        auto subjMarkIt = lookForSub(subjName);
        if ((*subjMarkIt) != nullptr)
        {
            (*subjMarkIt)->marks_list.push_back(mark);
            float av_mark = 0;
            for (const auto& mark : (*subjMarkIt)->marks_list)
            {
                av_mark += mark;
            }
            av_mark /= (*subjMarkIt)->marks_list.size();
            (*subjMarkIt)->averMark = av_mark;
            return av_mark;
        }

    }

    void print(void) {
        char buff[256];
        sprintf(buff, "%s %s, %u лет, студенческий №: %s", info->name, info->age, info->ID);
        cout << buff << endl;
        for (list<Mark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            sprintf(buff, "предмет: %s; средняя оценка: %.1f", (*it)->subj, (*it)->averMark);
            cout << buff << endl;
        }

    }
};
