#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <algorithm> 
#include<string>


using namespace std;
/*
isdigit() - ���ڸ� ��󳾶�
isalpha() - ���ڸ� ��󳾶�

string my_string;
vector<int> my_vector;

std::copy

auto it = std::copy(source1.begin(), source1.end(), result.begin());
std::copy(source2.begin(), source2.end(), it);
copy���� ��ȯ�� it�� result�� �ҽ�1�� �����͸� �����ϰ� �� �ڸ� ��ȯ
��ȯ�� it�� �̾ �ҽ�2�� �����͸� ����

std::remove

remove(my_vector.begin(),my_vector.end(),Ư����);
�����̳� ������ Ư������ ã�� �ڷκ����� �ӽð����� ä������

it = my_vector.erase(it);
it�� �޾Ƽ� �ش� �����͸� �����ϰ� �� �ڸ� ��ȯ

my_vector.erase(remove(my_vector.begin(), my_vector.end(), Ư����), my_vector.end());

erase�� std::remove�� �������� Ư������ �����̳� ���ο��� ���� ���� ����

��Ʈ�������� �ٸ� ��� ����
6��° ���ں��� 5���� ���� ���� 
my_string.erase(6, 5);

<numeric>
template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init);

template<class InputIt, class T, class BinaryOperation>
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op);

accumulate �� ��ȯ���� ������ ���� ���� �����

std::string sentence = std::accumulate(words.begin(), words.end(), std::string(""));
int custom_accumulation = std::accumulate(vec.begin(), vec.end(), 0,
        [](int acc, int val) {
            return acc + val * val;
        });
int product = std::accumulate(vec.begin(), vec.end(), 1,
        [](int acc, int val) {
            return acc * val;
        });

�����Լ��� ù��° �Ű������� �����Ȱ� , �ι�° �Ű������� ���� ���
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
} // ���ڿ����� ����(1~9) ���ϴ� ����

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
    }//���ڷ� �����°�� ó��

    return answer;
}
//���ڿ� ���� ���� ���ϴ� ����

���ĺ� �ҹ��ڿ� �빮�� ��ȯ�ϱ�

islower isupper tolower toupper
str = tolower(str);

*/
int main() {

	

	return 0;
}
