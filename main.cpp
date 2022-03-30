#include <iostream>
#include <string.h>

// ЗАДАНИЕ С ЁЛОЧКОЙ
void Pine(int height){
    for (int i = 0; i < height; i++){
        for(int j =0; j < height - 1 - i; j++){
            std::cout<< ' ';
        }
        for (int k = 0; k< (2*i +1); k++){
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

//ЗАДАНИЕ С КЛАССОМ
class Student{
private:
    char* name;
    int** lessons;
    int LessonsCount;
    int MarksCount;
public:
    Student(int LessonsCount){
        name = new char[256];
        MarksCount = 0;
        int **lessons = new int*[LessonsCount+1]; // будет предмет 1, предмет 2 и т.д.
        lessons[0]= new int[LessonsCount+1]; // первый "столбец" хранит количество оценок в каждом
        for(int i = 1; i < LessonsCount+1; i++)
            lessons[i] = new int[MarksCount]; // ну да нулевые массивы. оценок же нет, пока их не добавят
    }
    ~Student(){
        for (int i =0; i < LessonsCount; i++)
            delete [](lessons[i]);
        delete[](lessons);
    }
    void AddMark(int LessonIndex, int mark){ // LessonIndex - номер предмета в который добавляем оценку (ну прям вот индекс предмета в массиве lessons, тому що через char важко)
        int *array = new int[lessons[0][LessonIndex]];
        for (int i = 0; i < lessons[0][LessonIndex]; i++){
            array[i] = lessons[LessonIndex][i]; // копируем в темп
        }
        lessons[0][LessonIndex]++; //увеличить счетчик колва оценок в предмете
        lessons[LessonIndex] = new int[lessons[0][LessonIndex]]; // создаем новый
        for (int i = 0; i < lessons[0][LessonIndex]; i++){
            lessons[LessonIndex][i] = array[i]; // копируем в новый
        }
        lessons[LessonIndex][lessons[0][LessonIndex]-1] = mark; // добавляем новую оценку последней
        delete[]array;
    }
    void AddLesson(){
        int** temp = new int*[LessonsCount];
        for (int i = 0; i < LessonsCount; i++)
            temp[i] = new int[lessons[0][i]];
        for (int i = 0; i < LessonsCount+ 1; i++){
            for (int j = 0; j< lessons[0][i]; j++){
                temp[i][j] = lessons[i][j];// копируем в темп массив
            }
        }
        int **lessons = new int*[++LessonsCount+1]; //увеличиваем счетчик предметов и создаем на 1 "столбец" больше чтобы был столбец оценок
        for (int i = 0; i < LessonsCount; i++){
            lessons[i] = new int[temp[0][i]]; // чтобы колво оценок на каждом предмете осталось прежним
        }
        for (int i = 0; i< LessonsCount; i++){
            for (int j = 0; j < temp[0][i]; j++){
                lessons[i][j] = temp[i][j]; // копируем обратно
            }
            for (int i =0; i < LessonsCount; i++)
                delete [](temp[i]);
            delete[](temp); //ну удаляем темп массив......
        }// какой-то очень тупой метод, копирую туда-сюда блин, sorry....
    }
    float CalculateAverage(int LessonIndex){
        float res;
        for (int i =0; i < lessons[0][LessonIndex]; i++){
            res += lessons[LessonIndex][i];
        }
        res /= lessons[0][LessonIndex]; //сумму на колво
        return res;
    }
    void GetInfo(Student *a){
        std::cout << "Имя:";
        for (int i =0; i< strlen(a->name);i++)
            std::cout << a->name[i];
        for (int i = 1; i < a-> LessonsCount; i++){ // выводим с первого, потому что в нулевом количества оценок
            std::cout << '\n' << "Предмет " << i<< ". Оценки: ";
            for (int j = 0; j<lessons[0][i]; j++){
                std::cout << lessons[i][j] << " ";
            }
            std::cout << " Среднее по предмету: " << a->CalculateAverage(i);
        }
        std::cout << '\n';
    }
};
int main() {
    using namespace std;

    return 0;
}
