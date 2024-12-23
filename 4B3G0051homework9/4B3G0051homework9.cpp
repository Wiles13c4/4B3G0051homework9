#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Student {
private:
    string id;
    string name;
    string department;
public:
    Student(string id, string name, string department)
        : id(id), name(name), department(department) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
};

class Teacher {
private:
    string id;
    string name;
    string department;
public:
    Teacher(string id, string name, string department)
        : id(id), name(name), department(department) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
};

class Course {
private:
    string code;
    string name;
    string teacherId;
    int credits;
public:
    Course(string code, string name, string teacherId, int credits)
        : code(code), name(name), teacherId(teacherId), credits(credits) {}

    string getCode() const { return code; }
    string getName() const { return name; }
    string getTeacherId() const { return teacherId; }
    int getCredits() const { return credits; }
};

class Enrollment {
private:
    string studentId;
    string courseCode;
    string semester;
public:
    Enrollment(string studentId, string courseCode, string semester)
        : studentId(studentId), courseCode(courseCode), semester(semester) {}

    string getStudentId() const { return studentId; }
    string getCourseCode() const { return courseCode; }
    string getSemester() const { return semester; }
};

class ManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;
    vector<Enrollment> enrollments;

public:
    void addStudent(const Student& student) {
        for (const auto& s : students) {
            if (s.getId() == student.getId()) {
                cout << "學生學號已存在，無法新增！" << endl;
                return;
            }
        }
        students.push_back(student);
    }

    void addTeacher(const Teacher& teacher) {
        teachers.push_back(teacher);
    }

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void addEnrollment(const Enrollment& enrollment) {
        enrollments.push_back(enrollment);
    }

    void listAllStudents() {
        cout << "學號\t姓名\t系所" << endl;
        for (const auto& student : students) {
            cout << student.getId() << "\t"
                << student.getName() << "\t"
                << student.getDepartment() << endl;
        }
        pause();
    }

    void listAllCourses() {
        cout << "代碼\t名稱\t教師編號\t學分" << endl;
        for (const auto& course : courses) {
            cout << course.getCode() << "\t"
                << course.getName() << "\t"
                << course.getTeacherId() << "\t\t"
                << course.getCredits() << endl;
        }
        pause();
    }

    void listAllTeachers() {
        cout << "編號\t姓名\t系所" << endl;
        for (const auto& teacher : teachers) {
            cout << teacher.getId() << "\t"
                << teacher.getName() << "\t"
                << teacher.getDepartment() << endl;
        }
        pause();
    }

    void listAllEnrollments() {
        cout << "學號\t課程代碼\t學期" << endl;
        for (const auto& enrollment : enrollments) {
            cout << enrollment.getStudentId() << "\t"
                << enrollment.getCourseCode() << "\t\t"
                << enrollment.getSemester() << endl;
        }
        pause();
    }

    void lookupStudent(const string& id) {
        bool found = false;
        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "學號: " << student.getId() << endl;
                cout << "姓名: " << student.getName() << endl;
                cout << "系所: " << student.getDepartment() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "找不到該學生，請重試或返回主選單。" << endl;
        }
        pause();
    }

    void pause() {
        cout << "按任意鍵繼續...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

void showMenu() {
    cout << "1. 列出學生資料" << endl;
    cout << "2. 列出課程資料" << endl;
    cout << "3. 列出教師資料" << endl;
    cout << "4. 列出選課紀錄" << endl;
    cout << "5. 查詢學生資料" << endl;
    cout << "0. 退出" << endl;
    cout << "請選擇操作: ";
}

int getMenuOption() {
    string input;
    getline(cin, input);
    try {
        return stoi(input);
    }
    catch (...) {
        return -1; // 表示無效選項
    }
}

int main() {
    ManagementSystem system;

    // 新增測試資料
    system.addStudent(Student("S001", "謝承芳", "資訊工程系"));
    system.addStudent(Student("S002", "葉恩齊", "電機工程系"));
    system.addTeacher(Teacher("T001", "陳老師", "資訊工程系"));
    system.addCourse(Course("C001", "程式設計", "T001", 3));
    system.addEnrollment(Enrollment("S001", "C001", "111-1"));

    while (true) {
        showMenu();
        int option = getMenuOption();

        switch (option) {
        case 1:
            system.listAllStudents();
            break;
        case 2:
            system.listAllCourses();
            break;
        case 3:
            system.listAllTeachers();
            break;
        case 4:
            system.listAllEnrollments();
            break;
        case 5: {
            cout << "請輸入學號: ";
            string id;
            getline(cin, id);
            system.lookupStudent(id);
            break;
        }
        case 0:
            return 0;
        default:
            cout << "無效的選擇，請重試！" << endl;
            system.pause();
        }
    }

    return 0;
}
