
#include <bits/stdc++.h>
#include <fstream>
// #include "INS.h"
using namespace std;
void CourseInstructorDetails_temp();
class Student
{
public:
    Student()
    {
    }
    Student(int a)
    {
        cout << "\t\t\t-------------------------------------\t\t\t" << endl;
        cout << "\t\t\t WELCOME TO ...INSTITUDE                   " << endl;
        cout << "\t\t\t-------------------------------------\t\t\t" << endl;
    RAM:
        cout << "NEW REGISTRATION --(Enter 0) " << endl;
        cout << "LOGIN -- (Enter 1) " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            Registration();
            goto RAM;
            break;
        case 1:
            LogIn();
        default:
            cout << "Incorrect data" << endl;
        }
    }
    string Student_Name, Mobile_NO, Address, Email_Id, Course_Name, Enrollment_NO, Password, Course_ID;
    void Registration();
    string CourseIDFun(string CourseID);
    void LogIn();
    int MinorTest(string Enroll_temp);
    void updateMarks(string Enroll_temp, int marks_temp);
    int questionWithID(int qid);
    void modify(string EnrollTemp);
    int correctAns(char ans, char StudentAns);
};
string Student::CourseIDFun(string CourseID)
{
    for (int i = 0; i < CourseID.length(); i++)
    {
        CourseID[i] = toupper(CourseID[i]);
    }
    map<string, int> m = {{"CPP", 1}, {"C", 2}, {"DBMS", 3}, {"PYTHON", 4}, {"JAVA", 5}};
    int c = m.at(CourseID);
    switch (c)
    {
    case 1:
        return "C001cpp";
    case 2:
        return "C002c";
    case 3:
        return "C003dbms";
    case 4:
        return "C004py";
    case 5:
        return "C005java";
    default:
        cout << "Wrong Data-- Error " << endl;
    }
    return "";
}
void Student::Registration()
{
    srand(time(0));
    cout << "\t---Fill the following details---\t " << endl;
    cout << "Full Name(First and Last Name): ";
    fflush(stdin);
    getline(cin, Student_Name);
    cout << "\nContact Number: ";
    while (true)
    {
        cin >> Mobile_NO;
        if (Mobile_NO.size() == 10)
            break;
        cout << "\n Invalid! ... Re-Enter: ";
    }
    cout << "\nEmail_ID: ";
    while (true)
    {
        cin >> Email_Id;
        string email_temp = "@";
        if (Email_Id.find(email_temp) != string::npos)
            break;
        cout << "/n Invalid: Re-Enter: ";
    }
    cout << "\nState: ";
    fflush(stdin);
    getline(cin, Address);
    cout << "Our courses DBMS/CPP/C/PYTHON.." << endl;
    cout << "\nCourse: ";
    cin >> Course_Name;
    cout << "\nThanks for Registration : \n Now you can access Your Course \n Check the Instruction given on front page: " << endl;
    int Enrollment_NO, Password1, Password2;
    srand(time(0));
    static int en = 10000; // to start the enrollemtn no /.
    Enrollment_NO = rand() % 1000000;
    Enrollment_NO += en;
    cout << "Your Enrollment Number is : " << Enrollment_NO << endl;
ram:
    cout << "Set Your Password : ";
    cin >> Password1;
    cout << "\nRe-Enter: " << endl;
    cin >> Password2;
    if (Password1 == Password2)
    {
        cout << "Done!..." << endl;
    }
    else
    {
        cout << "Incorrect - Re-enter: " << endl;
        goto ram;
    }
    cout << "Your Course ID: " << endl;
    Course_ID = CourseIDFun(Course_Name);
    cout << Course_ID << endl;
    ofstream myFile, myFile1;
    myFile.open("StudentProject11.csv", ios::app);
    if (myFile.is_open())
    {
        myFile << Enrollment_NO << "," << Password1 << "," << Student_Name << "," << Mobile_NO << ","
               << Email_Id << "," << Address << "," << Course_Name << "," << Course_ID << endl;
        myFile.close();
    }
    cout << "Your Registration is successfully Done!...Now u can access your classes" << endl;
}

void Student::LogIn()
{
    cout << "\t\t\t----------------------------------------\t\t\t" << endl;
    cout << "\t\t\t-------------Check Menu Bar-------------\t\t\t" << endl;
    int temp1 = 1;
    string enrolltemp, passtemp;
    while (temp1 < 4)
    {
        fstream fin;
        fin.open("StudentProject11.csv", ios::in);
        int roll2, pass2, count = 0;
        cout << "Enter Enrollment Number: ";
        cin >> enrolltemp;
        cout << "\nEnter Passward : ";
        cin >> passtemp;
        cout << endl
             << endl;
        vector<string> row;
        string line, word, temp;

        while (getline(fin, temp))
        {
            row.clear();

            stringstream s(temp);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row[0] == enrolltemp && row[1] == passtemp)
            {
                count = 1;
            }
        }
        if (count == 1)
            break;
        temp1++;
    }
    if (temp1 == 4)
    {
        cout << "You Are not Registered: " << endl;
        Registration();
    }

ram:
    cout << "\t\t\tMENU:\t\t\t " << endl;
    cout << "\tEnter 1 for Access Minor Test" << endl;
    cout << "\tEnter 2 for Access Major Test" << endl;
    cout << "\tEnter 3 for Change your Personal Details" << endl;
    cout << "\tEnter 4 for Access Course instructor Details or INSTITUDE Details" << endl;
    cout << "\tEnter 5 for Check Your Class Student Details" << endl;
    cout << "\tEnter 6 for Any Complaint/query to Course instructor" << endl;
    cout << "\tEnter 7 for Any Course/query to Institude Department" << endl;
    int temp2;
    cin >> temp2;
    int temp;
    switch (temp2)
    {
    case 1:
        temp = MinorTest(enrolltemp);
        cout << "Your Marks in this test is: " << temp;
        goto ram;
    case 2:
        // temp = MajorTest(enrolltemp);
        cout << "Your Marks in this test is: " << temp;
        goto ram;
    case 3:
        modify(enrolltemp); // update function to Change or update student details....
        goto ram;
    case 4:
        CourseInstructorDetails_temp();
        cout << "ram4";
        break;
    case 5:
        // CourseStudentList(enrolltemp);
        cout << "ram";
        break;
    case 6:
        break;
    }
}
int Student::MinorTest(string enrolltemp)
{
    cout << "\n\n\t\t\t*****************************" << endl;
    cout << "\t\t\t\t   MINOR TEST           " << endl;
    cout << "\n\n\t\t\t*****************************" << endl;
    int Test_NO_id;
    cout << "\t\t\tEnter the next Test Number: ";
    cin >> Test_NO_id;
    int ans;
    int a = rand() % 2;
    switch (Test_NO_id)
    {
    case 1:

        char StudentAns;
        switch (a)
        {
        case 0:
            ans = questionWithID(123010);
            updateMarks(enrolltemp, ans);
            return ans;

        case 1:

            ans = questionWithID(123011);
            updateMarks(enrolltemp, ans);

            return ans;
        }
        break;
    case 2:
        switch (a)
        {
        case 0:
            ans = questionWithID(123120);
            updateMarks(enrolltemp, ans);
            return ans;
            break;
        case 1:
            ans = questionWithID(123121);
            updateMarks(enrolltemp, ans);
            return ans;
        }
        break;
    case 3:
        switch (a)
        {
        case 0:
            ans = questionWithID(123230);
            updateMarks(enrolltemp, ans);
            return ans;
        case 1:
            ans = questionWithID(123231);
            updateMarks(enrolltemp, ans);
            return ans;
        }
        break;
    case 4:
        switch (a)
        {
        case 0:
            ans = questionWithID(123340);
            updateMarks(enrolltemp, ans);
            return ans;
        case 1:
            ans = questionWithID(123341);
            updateMarks(enrolltemp, ans);
            return ans;
        }
        break;
    case 5:
        switch (a)
        {
        case 0:
            ans = questionWithID(123450);
            updateMarks(enrolltemp, ans);
            return ans;
        case 1:
            ans = questionWithID(123451);
            updateMarks(enrolltemp, ans);
            return ans;
        }
        break;
    default:
        cout << "You completed all your Minor tests..Now ready for Major\n\t\t\tBest Wishes..!" << endl;
    }
    return 0;
}
void Student::updateMarks(string Enroll_temp1, int marks_temp)
{
    // system("cls");
    fstream fin, fout;
    fin.open("reportcard.csv", ios::in);
    fout.open("reportcardnew.csv", ios::out);
    int count = 0, i;
    int index = 1;
    string line, word;
    vector<string> row;
    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        int row_size = row.size();
        if (row_size != 0 && Enroll_temp1 == row[0])
        {
            count = 1;
            int mar_ = stoi(row[1]);
            mar_ += marks_temp;
            stringstream convert;
            convert << mar_;
            row[index] = convert.str();
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (row_size != 0 && !fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
    {
        fout << Enroll_temp1 << "," << marks_temp << endl;
    }
    fin.close();
    fout.close();
    remove("reportcard.csv");
    rename("reportcardnew.csv", "reportcard.csv");
}
int Student::correctAns(char ans, char StudentAns)
{
    if (ans == StudentAns)
    {
        cout << "WOW!...You are corrent..." << endl;
        // Sleep(4000);
        cout << "Congrats...\n\t\t\t" << endl;
        return 2;
    }
    else
    {
        cout << "Sorry!...You are incorrect..." << endl;
        cout << "Correct ans is : " << ans << endl;
        return 0;
    }
}
int Student::questionWithID(int qid)
{
    int ma;
    switch (qid)
    {
    case 0:
    case 123010:
        cout << "1.Which of the following is the correct syntax to add the header file in the C++ program?" << endl;
        cout << "a.#include<userdefined.h>" << endl;
        cout << "b.#include \"userdefined\"" << endl;
        cout << "c.<include> \"userdefined.h\"" << endl;
        cout << "d.Both A and B" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        char StudentAns;
        cin >> StudentAns;
        ma = correctAns('a', StudentAns);
        break;
    case 123011:
        cout << "2.Which of the following is the correct identifier?" << endl;
        cout << "a.$var_name" << endl;
        cout << "b.VAR_123" << endl;
        cout << "varname@" << endl;
        cout << "None of the above" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('b', StudentAns);
        break;
        break;
    case 1:
    case 123120:
        cout << "3.Which of the following features must be supported by any programming language to become a pure object-oriented programming language?" << endl;
        cout << "a.Encapsulation" << endl;
        cout << "b.Inheritance" << endl;
        cout << "c.Polymorphism" << endl;
        cout << "d.All of the above" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('d', StudentAns);
        break;
    case 123121:
        cout << "4.Which of the following is the original creator of the C++ language?" << endl;
        cout << "a.Dennis Ritchie" << endl;
        cout << "b.Ken Thompson" << endl;
        cout << "c.Bjarne Stroustrup" << endl;
        cout << "d.Brian Kernighan" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('a', StudentAns);
        break;
        break;
    case 2:
    case 123230:
        cout << "5. Which of the following comment syntax is correct to create a single-line comment in the C++ program?" << endl;
        cout << "a.//Comment" << endl;
        cout << "b./Comment/" << endl;
        cout << "c.Comment//" << endl;
        cout << "d.None of the above" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('a', StudentAns);
        break;
    case 123231:
        cout << "6.If we stored eight elements or data items in an array, what will be the index address or the index number of the array's last data item?" << endl;
        cout << "a.3" << endl;
        cout << "b.5" << endl;
        cout << "c.7" << endl;
        cout << "d.88" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('c', StudentAns);
        break;
        break;
    case 3:
    case 123340:
        cout << "7.How many types of elements can an array store?" << endl;
        cout << "a.Same types of elements" << endl;
        cout << "b.Char and int type" << endl;
        cout << "c.Only char types" << endl;
        cout << "d.All of the above" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('a', StudentAns);
        break;
    case 123341:
        cout << "8..Which of the following can be considered as the correct syntax for declaring an array of pointers of integers that has a size of 10 in C++?" << endl;
        cout << "a.int arr = new int[10];" << endl;
        cout << "b.int *arr = new int*[10]" << endl;
        cout << "c.int **arr = new int*[10];" << endl;
        cout << "d.int *arr = new int[10];" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('c', StudentAns);
        break;
        break;
    case 4:
    case 123450:
        cout << "Which type of approach is used by the C++ language?" << endl;
        cout << "a.Right to left" << endl;
        cout << "b.Left to right" << endl;
        cout << "c.Top to bottom" << endl;
        cout << "d.Bottom-up" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('d', StudentAns);
        break;
    case 123451:
        cout << "What is a constant that contains a single character enclosed within single quotes?" << endl;
        cout << "a.Character" << endl;
        cout << "b.Numeric" << endl;
        cout << "c.Fixed" << endl;
        cout << "d.Floating point" << endl;
        cout << "\n\t\tChoice out of four options write in small letter a-b-c-d " << endl;
        cout << "Enter Your Choice: ";
        cin >> StudentAns;
        ma = correctAns('a', StudentAns);
        break;
    }
    return ma;
}
void Student::modify(string Enrolltemp)
{
    string Student_Name1;
    cout << "\nEnter Your Name: ";
    getline(cin, Student_Name1);
    getline(cin, Student_Name1);
    string Mobile_NO1;
    cout << "\nEnter Your Mobile_NO: ";
    while (true)
    {
        cin >> Mobile_NO1;
        if (Mobile_NO1.size() == 10)
            break;
        cout << "\n Invalid! ... Re-Enter: ";
    }
    string Address1;
    cout << "\nEnter Your State: ";
    getline(cin, Address1);
    getline(cin, Address1);
    string Email_Id1;
    cout << "\nEnter Your Email_Id: ";
    while (true)
    {
        cin >> Email_Id1;
        string email_temp = "@";
        if (Email_Id1.find(email_temp) != string::npos)
            break;
        cout << "/n Invalid: Re-Enter" << endl;
    }
    string Password1;
    cout << "\nSet New Passward: ";
    cin >> Password1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    fstream fin, fout;
    fin.open("StudentProject11.csv", ios::in);
    fout.open("tempnew.csv", ios::out);
    int count = 0, i;
    int index = 1;
    string line, word;
    vector<string> row;
    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        int row_size = row.size();
        if (row_size != 0 && Enrolltemp == row[0])
        {
            count = 1;
            if (!fin.eof())
            {
                fout << Enrolltemp << "," << Password1 << "," << Student_Name1 << "," << Mobile_NO1
                     << "," << Email_Id1 << "," << Address1 << "," << row[6] << "," << row[7] << endl;
            }
        }
        else
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
    {
        cout << "No data" << endl;
    }

    fin.close();
    fout.close();
    remove("StudentProject11.csv");
    rename("tempnew.csv", "StudentProject11.csv");
}

class CourseInstructor : public Student
{
public:
    string Iname;
    string FId;
    string IAddress;
    string IEmail_Id;
    string ICourse;
    string Iqualification;
    string IExpericence;
    string Fpassword;
    void loginCourse();
    CourseInstructor()
    {
    }
    CourseInstructor(int a)
    {
    Ram1:
        cout << "Enter 1 for Sign-up: " << endl;
        cout << "Enter 2 for Login: " << endl;
        int aa;
        cin >> aa;
        switch (aa)
        {
        case 1:
            InstructorRegis();
            goto Ram1;
            break;
        case 2:
            loginCourse();
            goto Ram1;
        }
    }

public:
    // access from instructor table
    // name,course,email,qualif,expe
    // this below fun is access when our institude student will acces....
    friend void CourseInstructorDetails();

private:
    string IContact;
    string AboutSection;

public:
    void StudentDetailsRelatedToCourse()
    {
        cout << "Choice 1 if You are a courseInstructor: " << endl;
        cout << "Choice 2 if Yor are a InstitudeDeparement: " << endl;
        int aa;
        cin >> aa;
        switch (aa)
        {
        case 1:
        {
            cout << "Enter Your CourseId :   ";
            cin >> Course_ID;
            cout << "\n";
            //....open file....
            fstream fin;
            fin.open("StudentProject11.csv", ios::in);
            int count = 0;

            vector<string> row;
            string line, word, temp;
            cout << "*******************StudentData*************\n";
            while (getline(fin, temp))
            {
                row.clear();

                stringstream s(temp);

                while (getline(s, word, ','))
                {
                    row.push_back(word);
                }
                if (row[7] == Course_ID)
                {
                    cout << "Student_Name: " << row[2] << endl;
                    cout << "Mobile_no: " << row[3] << endl;
                    cout << "Email_Id: " << row[4] << endl;
                }
                cout << "-----------------" << endl;
            }

            break;
        }
        case 2:
        {
            fstream fin;
            fin.open("StudentProject11.csv", ios::in);
            int count = 0;

            vector<string> row;
            string line, word, temp;
            cout << "*******************StudentData*************\n";
            while (fin >> temp)
            {
                row.clear();

                stringstream s(temp);

                while (getline(s, word, ','))
                {
                    row.push_back(word);
                }
                cout << "Enrollment_NO : " << row[0] << endl;
                cout << "Student_Name : " << row[2] << endl;
                cout << "Mobile_No : " << row[3] << endl;
                cout << "EmailID : " << row[4] << endl;
                cout << "Address : " << row[5] << endl;
                cout << "CourseName : " << row[6] << endl;
                cout << "CourseId : " << row[7] << endl;
            }
            break;
        }
        default:
            cout << "wrong data.........." << endl;
        }
    }
    void InstructorRegis()
    {
        cout << "Enter Your Name: ";
        getline(cin, Iname);
        getline(cin, Iname);
        cout << "\nState: ";
        fflush(stdin);
        getline(cin, IAddress);
        cout << "\nEmail Id: ";
        while (true)
        {
            cin >> IEmail_Id;
            string email_temp = "@";
            if (IEmail_Id.find(email_temp) != string::npos)
                break;
            cout << "/n Invalid: Re-Enter: ";
        }
        cout << "\nQualification(): ";
        fflush(stdin);
        getline(cin, Iqualification);
        cout << "\nExperiance: ";
        cin >> IExpericence;
        cout << "\nEnter Your Contact Number: ";
        while (true)
        {
            cin >> IContact;
            if (IContact.size() == 10)
                break;
            cout << "\n Invalid! ... Re-Enter: ";
        }
        cout << "Our courses DBMS/CPP/C/PYTHON.." << endl;
        cout << "\nCourse: ";
        cin >> Course_Name;
        cout << "\nYour Course ID: " << endl;
        string Course_ID = CourseIDFun(Course_Name);
        cout << Course_ID << endl;
        cout << "\nAboutSection(Enter in less than 100 words): ";
        fflush(stdin);
        getline(cin, AboutSection);
        string TempforId = "F001";
        int randomNo = rand() % 10000 + 1000;
        FId = TempforId + to_string(randomNo);
        cout << "Your FId is : " << FId << endl;
        string Ftemp1;
    Ram2:
        cout << "Set Your Password: ";
        cin >> Ftemp1;
        string Ftemp2;
        cout << "\nRe-enter Your Password: ";
        cin >> Ftemp2;
        if (Ftemp1 == Ftemp2)
        {
            cout << "Done!...You Successfully Sigup ...." << endl;
            Fpassword = Ftemp1;
        }
        else
        {
            cout << "Wrong Password, \t renter: ";
            goto Ram2;
        }
        fstream myFile;
        myFile.open("FacultyData.csv", ios::app);
        if (myFile.is_open())
        {
            myFile << FId << "," << Fpassword << "," << Iname << "," << IAddress << "," << IEmail_Id << ","
                   << Iqualification << "," << Course_ID << "," << IExpericence << "," << AboutSection << "," << IContact << endl;
            myFile.close();
        }
    }
};
void CourseInstructor::loginCourse()
{
    cout << "\t\t\t----------------------------------------\t\t\t" << endl;
    cout << "\t\t\t-------------Check Menu Bar-------------\t\t\t" << endl;
    int temp1 = 1;
    int enrolltemp;
    while (temp1 < 4)
    {
        fstream fin;
        fin.open("FacultyData.csv", ios::in);
        int roll2, pass2, count = 0;
        cout << "Enter You FID: ";
        cin >> FId;
        cout << "\nEnter Passward : ";
        cin >> Fpassword;
        cout << endl
             << endl;
        vector<string> row;
        string line, word, temp;

        while (fin >> temp)
        {
            row.clear();

            stringstream s(temp);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            if (row[0] == FId && row[1] == Fpassword)
            {
                count = 1;
            }
        }
        if (count == 1)
            break;
        temp1++;
    }
    if (temp1 == 4)
    {
        cout << "----------Sorry Sir, You are not register--------: " << endl;
        cout << "------------Fill the form-------------------" << endl;
        InstructorRegis();
    }

ram:
    cout << "\t\t\tMENU:\t\t\t " << endl;
    cout << "\tEnter 1 for Check Your Class Student Details" << endl;
    cout << "\tEnter 2 for Any Complaint/query " << endl;
    int c1;
    cin >> c1;
    if (c1 == 1)
    {
        StudentDetailsRelatedToCourse();
    }
    else
    {
        cout << "no......." << endl;
    }
}
void CourseInstructorDetails()
{
    fstream fin;
    fin.open("FacultyData.csv", ios::in);
    int count = 0;
    vector<string> row;
    string line, word, temp;
    cout << "*******************FacultyData*************\n";
    while (getline(fin, temp))
    {
        row.clear();

        stringstream s(temp);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        cout << "Name of CourseInstructor: " << row[2] << endl;
        cout << "About : " << row[8] << endl
             << endl;
    }
}
void CourseInstructorDetails_temp()
{
    CourseInstructorDetails();
}

class InstitudeDepartment : public CourseInstructor
{
public:
    InstitudeDepartment(int a)
    {
        cout << "Faculty Data(Press 1): ";
        cout << "Student Data(Press 2): ";
        cout << "Institude (Press 3): ";
        int c1;
        cin >> c1;
        if (c1 == 1)
        {
            StudentDetailsRelatedToCourse();
        }
        else if (c1 == 2)
        {
            fstream fin;
            fin.open("FacultyData.csv", ios::in);
            int count = 0;

            vector<string> row;
            string line, word, temp;
            cout << "*******************FacultyData*************\n";
            while (fin >> temp)
            {
                row.clear();

                stringstream s(temp);

                while (getline(s, word, ','))
                {
                    row.push_back(word);
                }
                cout << "FID : " << row[0] << endl;
                cout << "Name : " << row[2] << endl;
                cout << "Address : " << row[3] << endl;
                cout << "EmailID : " << row[4] << endl;
                cout << "Qualification : " << row[5] << endl;
                cout << "CourseID : " << row[6] << endl;
                cout << "Expericence : " << row[7] << endl;
                cout << "About : " << row[8] << endl;
                cout << "Contact : " << row[9] << endl;
                cout << "-----------------------------" << endl;
            }
        }
        else
        {
            // INS ins;
            cout<<"nothing";
        }
    }
};
void InstitudeDetails()
{
    cout << "\t\t\t-------------------------------------\t\t\t" << endl;
    cout << "\t\t\t WELCOME TO ...Ray Institude ............ " << endl;
    cout << "\t\t\t-------------------------------------\t\t\t" << endl;
    cout << "Our vision is that all the students should get the same educatioin" << endl;
}
void Latest_update()
{
    cout << "\t\t\t-------------------------------------\t\t\t" << endl;
    cout << "\t\t\t Starting Interview Preparation Bootcamp from 15/12/2022 ............ " << endl;
    cout << "\t\t\t Last Date for Registration 12/12/2022............ " << endl;
    cout << "\t\t\t-------------------------------------\t\t\t" << endl;
}
int main()
{
    InstitudeDetails();
r:
    cout << "Enter 1 for Student: " << endl;
    cout << "Enter 2 for CourseInstructor: " << endl;
    cout << "Enter 3 (To know about our Faculties)" << endl;
    cout << "Enter 4 (Latest Update)" << endl;
    cout << "Enter 5 (For Institude Members) " << endl;
    int c;
    cin >> c;
    if (c == 1)
    {
        Student s(1);
        goto r;
    }
    else if (c == 2)
    {
        CourseInstructor C(2);
        goto r;
    }
    else if (c == 3)
    {
        CourseInstructorDetails();
        goto r;
    }
    else if (c == 4)
    {
        Latest_update();
        goto r;
    }
    else
    {
        InstitudeDepartment(5);
        goto r;
    }
}