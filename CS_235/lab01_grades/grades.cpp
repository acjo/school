#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[])
{
    VS_MEM_CHECK

    string inputDataFile;
    string outputDataFile;
    string firstName;
    string lastName;
    ifstream dataInput;
    ofstream dataOutput;
    int numStudents;
    int numExams;

    cout << "Enter the path to the input file and press enter: ";
    getline(cin, inputDataFile);
    cout << "Enter the path to the output file and press enter: ";
    getline(cin, outputDataFile);

    dataInput.open(inputDataFile);
    if (!dataInput.is_open())
    {
        cout << "Unable to open file: " << inputDataFile << endl;
        return 0;
    }

    dataInput >> numStudents;
    dataInput >> numExams;
    string* studentNames = new string[numStudents];
    double* examAverages = new double[numExams];
    double** examScores = new double* [numStudents];
    string** examLetterGrades = new string* [numStudents];
    for (unsigned int i = 0; i < numStudents; ++i)
    {
        examScores[i] = new double[numExams];
        examLetterGrades[i] = new string[numExams];
    }

    for (unsigned int i = 0; i < numStudents; ++i)
    {
        dataInput >> firstName;
        dataInput >> lastName;
        studentNames[i] = firstName + " " + lastName;
        for (unsigned int j = 0; j < numExams; ++j)
            dataInput >> examScores[i][j];
    }
    dataInput.close();

    dataOutput.open(outputDataFile);
    dataOutput << "Student Scores:" << endl;
    for (unsigned int i = 0; i < numStudents; ++i)
    {
        dataOutput << setw(20) << studentNames[i];
        for (unsigned int j = 0; j < numExams; ++j)
        {
            if (j == 0)
                dataOutput << setw(7) << examScores[i][j];
            else
                dataOutput << setw(6) << examScores[i][j];
        }
        dataOutput << endl;
    }

    dataOutput << "Exam Averages:" << endl;
    for (unsigned int i = 0; i < numExams; ++i)
    {
        for(unsigned int j = 0; j < numStudents; ++j)
        {
            if (j == 0)
                examAverages[i] = examScores[j][i];
            else
                examAverages[i] += examScores[j][i];
        }
        examAverages[i] = examAverages[i] / numStudents;
        dataOutput << fixed << setprecision(1);
        dataOutput << setw(9) << "Exam " << i + 1 <<  " Average =" << setw(7) << examAverages[i] << endl;
    }

    dataOutput <<setprecision(0) << "Student Exam Grades:" << endl;
    for (unsigned int i = 0; i < numStudents; ++i)
    {
        dataOutput << setw(20) << studentNames[i];
        for (unsigned int j = 0; j < numExams; ++j)
        {
            if (examScores[i][j] + 5 >= examAverages[j] && examScores[i][j] - 5 <= examAverages[j])
            {
                examLetterGrades[i][j] = "(C)";
                dataOutput << setw(6) << examScores[i][j] << examLetterGrades[i][j];
            }
            else if (examScores[i][j] - 5 > examAverages[j] && examScores[i][j] - 15 < examAverages[j])
            {
                examLetterGrades[i][j] = "(B)";
                dataOutput << setw(6) << examScores[i][j] << examLetterGrades[i][j];

            }
            else if (examScores[i][j] + 5 < examAverages[j] && examScores[i][j] + 15 > examAverages[j])
            {
                examLetterGrades[i][j] = "(D)";
                dataOutput << setw(6) << examScores[i][j] << examLetterGrades[i][j];
            }
            else if (examScores[i][j] - 15 >= examAverages[j])
            {
                examLetterGrades[i][j] = "(A)";
                dataOutput << setw(6) << examScores[i][j] << examLetterGrades[i][j];
            }
            else
            {
                examLetterGrades[i][j] = "(E)";
                dataOutput << setw(6) << examScores[i][j] << examLetterGrades[i][j];
            }
        }
        dataOutput << endl;
    }

    dataOutput << "Exam Grades:" << endl;
    for (unsigned int i = 0; i < numExams; ++i)
    {
        int aCount = 0;
        int bCount = 0;
        int cCount = 0;
        int dCount = 0;
        int eCount = 0;
        for (unsigned int j = 0; j < numStudents; ++j)
        {
            if (examLetterGrades[j][i] == "(A)")
                ++aCount;
            else if (examLetterGrades[j][i] == "(B)")
                ++bCount;
            else if (examLetterGrades[j][i] == "(C)")
                ++cCount;
            else if (examLetterGrades[j][i] == "(D)")
                ++dCount;
            else
                ++eCount;
        }
        dataOutput << setw(8) << "Exam" << setw(3) << i + 1 << setw(5) << aCount << "(A)" << setw(5) << bCount << "(B)"
            << setw(5) << cCount << "(C)" << setw(5) << dCount << "(D)" << setw(5) << eCount << "(E)" << endl;
    }

    dataOutput << "Student Final Grades:" << endl;
    double classExamAverage = 0;
    for (unsigned int i = 0; i < numStudents; ++i)
        for (unsigned int j = 0; j < numExams; ++j)
            classExamAverage += examScores[i][j];

    classExamAverage = classExamAverage / (numStudents * numExams);
    for (unsigned int i = 0; i < numStudents; ++i)
    {
        double studentGrade = 0;
        dataOutput << setprecision(1) << setw(20) << studentNames[i];
        for (unsigned int j = 0; j < numExams; ++j)
            studentGrade += examScores[i][j];
    
        studentGrade = studentGrade / numExams;
        if (studentGrade + 5 >= classExamAverage  && studentGrade - 5 <= classExamAverage)
            dataOutput << setw(6) << studentGrade << "(C)";
        else if (studentGrade - 5 > classExamAverage && studentGrade - 15 < classExamAverage)
            dataOutput << setw(6) << studentGrade << "(B)";
        else if (studentGrade + 5 < classExamAverage && studentGrade + 15 > classExamAverage)
            dataOutput << setw(6) << studentGrade << "(D)";
        else if (studentGrade - 15 >= classExamAverage)
            dataOutput << setw(6) << studentGrade << "(A)";
        else
            dataOutput << setw(6) << studentGrade << "(E)";
    
        dataOutput << endl;
    }
    dataOutput << "Class Average Score = " << classExamAverage;
    dataOutput.close();

    for (int i = 0; i < numStudents; ++i)
    {
        delete[] examScores[i];
        delete[] examLetterGrades[i];
    }
    delete[] examScores;
    delete[] examLetterGrades;
    delete[] studentNames;
    delete[] examAverages;
    
    
    return 0;
}
