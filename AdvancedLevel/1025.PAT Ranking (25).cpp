/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations.
Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing 
the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with 
the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    long long registration_number; //考号
    int score;                     //得分
    int location_number;           //考场号
    int local_rank;                //考场内排名
}stu[30010];

bool cmp(student a, student b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.registration_number < b.registration_number;
}

int main(){
    int N, K, t, r;
    cin >> N;
    t = 0;           //考生数
    for(int i = 1; i <= N; i++) {
        cin >> K;
        for(int j = t; j < t + K; j++) {
            stu[j].location_number = i;
            cin >> stu[j].registration_number >> stu[j].score;
        }
        //考场内排名排序
        sort(stu + t, stu + t + K, cmp);
        stu[t].local_rank = 1;
        for(int j = t + 1; j < t + K; j++) {
            if(stu[j].score == stu[j - 1].score) stu[j].local_rank = stu[j - 1].local_rank;
            else stu[j].local_rank = j - t + 1;
        }
        t += K;
    }
    //总排名排序
    sort(stu, stu + t, cmp);
    r = 1;
    printf("%d\n", t);
    for(int i = 0; i < t; i++) {
        printf("%013lld ", stu[i].registration_number); //考号是整型注意前面补0，或改成字符串存储
        if(i > 0 && stu[i].score != stu[i - 1].score) r = i + 1;
        printf("%d %d %d", r, stu[i].location_number, stu[i].local_rank);
        if(i != t - 1) printf("\n");
    }

    return 0;
}