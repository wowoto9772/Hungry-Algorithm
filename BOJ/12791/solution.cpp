#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector <string> dic[2018];

char str[123312];

int main() {

	dic[1967].push_back("DavidBowie");
	dic[1969].push_back("SpaceOddity");
	dic[1970].push_back("TheManWhoSoldTheWorld");
	dic[1971].push_back("HunkyDory");
	dic[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	dic[1973].push_back("AladdinSane");
	dic[1973].push_back("PinUps");
	dic[1974].push_back("DiamondDogs");
	dic[1975].push_back("YoungAmericans");
	dic[1976].push_back("StationToStation");
	dic[1977].push_back("Low");
	dic[1977].push_back("Heroes");
	dic[1979].push_back("Lodger");
	dic[1980].push_back("ScaryMonstersAndSuperCreeps");
	dic[1983].push_back("LetsDance");
	dic[1984].push_back("Tonight");
	dic[1987].push_back("NeverLetMeDown");
	dic[1993].push_back("BlackTieWhiteNoise");
	dic[1995].push_back("1.Outside");
	dic[1997].push_back("Earthling");
	dic[1999].push_back("Hours");
	dic[2002].push_back("Heathen");
	dic[2003].push_back("Reality");
	dic[2013].push_back("TheNextDay");
	dic[2016].push_back("BlackStar");

	int t;
	scanf("%d", &t);

	while (t--) {

		int a, b;
		scanf("%d %d", &a, &b);

		int tot = 0;
		for (int i = a; i <= b; i++) {
			tot += dic[i].size();
		}

		printf("%d\n", tot);
		for (int i = a; i <= b; i++) {
			for (int j = 0; j < dic[i].size(); j++)printf("%d %s\n", i, dic[i][j].c_str());
		}

	}

}