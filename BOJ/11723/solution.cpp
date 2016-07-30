////#include <stdio.h>
////#include <string.h>
////
////char cmd[10];
////int chk[22];
////
////int main(){
////	int m;
////	scanf("%d", &m);
////
////	int x;
////	for (int i = 1; i <= m; i++){
////		scanf("%s", cmd);
////		if (strcmp(cmd, "all") && strcmp(cmd, "empty"))scanf("%d", &x);
////
////		if (!strcmp(cmd, "add")){
////			chk[x] = true;
////		}
////		else if (!strcmp(cmd, "check")){
////			printf("%d\n", chk[x] ? 1 : 0);
////		}
////		else if (!strcmp(cmd, "remove")){
////			chk[x] = false;
////		}
////		else if (!strcmp(cmd, "all")){
////			for (int j = 1; j <= 20; j++)chk[j] = true;
////		}
////		else if (!strcmp(cmd, "toggle")){
////			chk[x] ^= true;
////		}
////		else if (!strcmp(cmd, "empty")){
////			for (int j = 1; j <= 20; j++)chk[j] = false;
////		}
////	}
////}
//
//#include <stdio.h>
//
//char cmd[10];
//int chk[22];
//
//int main(){
//	int m;
//	scanf("%d", &m);
//
//	int x;
//	for (int i = 1; i <= m; i++){
//		scanf("%s", cmd);
//		if ((cmd[0] == 'a' && cmd[1] == 'l') || cmd[0] != 'e')scanf("%d", &x);
//
//		if (cmd[0] == 'a' && cmd[1] == 'd'){
//			chk[x] = true;
//		}
//		else if (cmd[0] == 'c'){
//			printf("%d\n", chk[x] ? 1 : 0);
//		}
//		else if (cmd[0] == 'r'){
//			chk[x] = false;
//		}
//		else if (cmd[0] == 'a' && cmd[1] == 'l'){
//			for (int j = 1; j <= 20; j++)chk[j] = true;
//		}
//		else if (cmd[0] == 't'){
//			chk[x] ^= true;
//		}
//		else if (cmd[0] == 'e'){
//			for (int j = 1; j <= 20; j++)chk[j] = false;
//		}
//	}
//}