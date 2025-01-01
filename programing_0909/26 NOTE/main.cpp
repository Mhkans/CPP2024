#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <algorithm> 
#include<string>


using namespace std;
/*
isdigit() - 숫자만 골라낼때
isalpha() - 문자만 골라낼때

string my_string;
vector<int> my_vector;

std::copy

auto it = std::copy(source1.begin(), source1.end(), result.begin());
std::copy(source2.begin(), source2.end(), it);
copy에서 반환된 it는 result에 소스1의 데이터를 저장하고 그 뒤를 반환
반환된 it에 이어서 소스2의 데이터를 저장

std::remove

remove(my_vector.begin(),my_vector.end(),특정값);
컨테이너 내에서 특정값을 찾아 뒤로보내서 임시값으로 채워넣음

it = my_vector.erase(it);
it를 받아서 해당 데이터를 제거하고 그 뒤를 반환

my_vector.erase(remove(my_vector.begin(), my_vector.end(), 특정값), my_vector.end());

erase와 std::remove의 조합으로 특정값을 컨테이너 내부에서 전부 삭제 가능

스트링에서는 다른 기능 지원
6번째 문자부터 5개의 문자 삭제 
my_string.erase(6, 5);

<numeric>
template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init);

template<class InputIt, class T, class BinaryOperation>
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op);

accumulate 의 반환값은 지정한 식을 행한 결과값

std::string sentence = std::accumulate(words.begin(), words.end(), std::string(""));
int custom_accumulation = std::accumulate(vec.begin(), vec.end(), 0,
        [](int acc, int val) {
            return acc + val * val;
        });
int product = std::accumulate(vec.begin(), vec.end(), 1,
        [](int acc, int val) {
            return acc * val;
        });

람다함수의 첫번째 매개변수는 누적된값 , 두번째 매개변수는 현재 요소
int solution(string my_string) {
    int answer = 0;
    answer = std::accumulate(my_string.begin(), my_string.end(), 0, [](int x, char a) {
        if (isdigit(a)) {
            return x + (a - '0');
        }
        else {
            return x;
        }
    });
    return answer;
} // 문자열내의 숫자(1~9) 더하는 예시

int solution(string my_string) {
    int answer = 0;
    string temp = "";
    for (auto num : my_string) {

        if (isdigit(num)) {

            temp += num;
        }
        else {
            if(!temp.empty())
            answer += stoi(temp);
            temp = "";
        }
    }
    if (!temp.empty()) {
        answer += stoi(temp);
    }//숫자로 끝나는경우 처리

    return answer;
}
//문자열 내의 숫자 더하는 예시

알파벳 소문자와 대문자 전환하기

islower isupper tolower toupper
str = tolower(str);

*/
int main() {

	

	return 0;
}
