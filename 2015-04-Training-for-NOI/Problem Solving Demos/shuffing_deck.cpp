#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Card{
	string face;
	string suit;

	Card();
	Card(string, string);
};

// ostream& operator<<(std::ostream&, const Card&);

void print(vector<Card>);

void performSingleExchange(vector<Card> &, int);

void shuffleDeck(vector<Card> &);

void testShuffleDeckNoCards();
void testShuffleDeck1Card();
void testShuffleDeck52Cards();
void testShuffleDeck52000Cards();

int main(){
	testShuffleDeckNoCards();
	testShuffleDeck1Card();
	testShuffleDeck52Cards();
	testShuffleDeck52000Cards();

	return 0;
}

Card::Card(){
}

Card::Card(string f, string s){
	this->face = f;
	this->suit = s;
}

void performSingleExchange(vector<Card> &deck, int index){
	static bool isSeedSet = false;
	if(!isSeedSet){
		srand(time(NULL));
		isSeedSet = true;
	}
	int randomIndex = 1 + (rand() % (deck.size() - 1));

	Card first = deck[index];
	Card randomCard = deck[randomIndex];
	deck[index] = randomCard;
	deck[randomIndex] = first;
}

void shuffleDeck(vector<Card> & deck){
	if(deck.size() <=1){
		return;
	}
	for(int i = 0, size = deck.size(); i < size; ++i){
		performSingleExchange(deck, i);
	}
}

void print(vector<Card> deck){
	static string line = "--------------------------------------";
	cout<<line<<endl;
	for(auto card : deck){
		cout << "(" << card.face << " of "<< card.suit << ")";
	}
	cout<<endl;
	cout<<line<<endl;
}

void testShuffleDeckNoCards(){
	vector<Card> deck;
	print(deck);
	shuffleDeck(deck);
	print(deck);
}

void testShuffleDeck1Card(){
	vector<Card> deck;
	deck.push_back(Card("A", "Spaces"));
	print(deck);
	shuffleDeck(deck);
	print(deck);
}

void testShuffleDeck52Cards(){
	string faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs" };
	int facesSize = sizeof(faces) / sizeof(string);
	int suitsSize = sizeof(suits) / sizeof(string);

	vector<Card> deck;

	for(string face:faces){
		for(string suit:suits){
			deck.push_back(Card(face, suit));
		}
	}
	print(deck);

	shuffleDeck(deck);
	print(deck);
}


void testShuffleDeck52000Cards(){
	string faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs" };
	vector<Card> deck;

	for(int i = 0; i < 1000; i++){
		for(string face:faces){
			for(string suit:suits){
				deck.push_back(Card(face, suit));
			}
		}
	}
	print(deck);

	shuffleDeck(deck);
	print(deck);
}






