#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    vector<int> N;
    vector<unsigned int> answer;

    void InputFormat() {
        LINE(T);
        LINE(N) % SIZE(T);
    }

    void OutputFormat() {
        LINE(answer) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= T && T <= 10);
    }

    void Subtask1(){
        Points(10);
        CONS(eachElementBetween(N, 3, 10));
    }

    void Subtask2(){
        Points(60);
        CONS(eachElementBetween(N, 11, 100000));
    }

    void Subtask3(){
        Points(30);
        CONS(eachElementBetween(N, 100001, 10000000));
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "3",
            "4"
        });
        Output({
            "10",
            "40"
        });
    }

    void BeforeTestCase(){
        N.clear();
    }

    void TestCases() {
        CASE(T = 8, N = {3, 4, 5, 6, 7, 8, 9, 10});
        CASE(T = 10, randomElements(11, 100));
        CASE(T = 10, randomElements(101, 1000));
        CASE(T = 10, randomElements(1001, 10000));
        CASE(T = 10, randomElements(10001, 100000));
        CASE(T = 10, randomElements(11, 100000));
        CASE(T = 10, randomElements(11, 100000));
        CASE(T = 10, randomElements(100001, 1000000));
        CASE(T = 10, randomElements(1000001, 1000000));
        CASE(T = 10, randomElements(100001, 10000000));
    }
private:
    void randomElements(int start, int end){
        for(int i = 0; i < 10; i++){
            N.push_back(rnd.nextInt(start, end));
        }
    }
};