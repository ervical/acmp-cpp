#include <cstdio>
#include <string> 

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	string keys = "qwertyuiopasdfghjklzxcvbnmq";
	char key;
	scanf("%c", &key);
	int pos = keys.find(key);
	printf("%c", keys[pos + 1]);
	return 0;
}
