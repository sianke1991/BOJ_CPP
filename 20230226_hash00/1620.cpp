#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	//problem at https://www.acmicpc.net/problem/1620
	int N, M; //N: number of pokemons, M: number of questions
	cin >> N >> M;
	string pokemonArray[N+1]; //convert int to string
	pokemonArray[0] = "";
	unordered_map<string, int> pokemonMap; //convert string to int
	string stringInput;
	for (int i=1; i<=N; i++) {
		cin >> stringInput;
		pokemonArray[i] = stringInput;
		pokemonMap[stringInput] = i;
	} //i loop
	string questions[M];
	string answers[M];
	for (int i=0; i<M; i++) {
		cin >> stringInput;
		questions[i] = stringInput;
	} //i loop
	string question;
	char firstCharacter;
	for (int i=0; i<M; i++) {
		question = questions[i];
		firstCharacter = question[0];
		if (firstCharacter>='0' && firstCharacter<='9') { //if the question string is (actually) a number
			answers[i] = pokemonArray[stoi(question)];
		} else {
			answers[i] = to_string(pokemonMap[question]);
		}
	} //i loop
	for (string answer:answers) {
		cout << answer << '\n';
	} //answer loop
	return 0;	
}