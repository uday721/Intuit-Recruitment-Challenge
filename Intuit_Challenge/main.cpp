#include<iostream>
#include<fstream>
#include<map>
#include<unordered_map>
#include<string>
#include <sstream>
#include<algorithm>
#include"ResourceManager.h"




template <class KTy, class Ty>
void PrintMap(unordered_map<KTy, Ty> map)
{
	
	typedef std::unordered_map<KTy, Ty>::iterator iterator;
	for (iterator p = map.begin(); p != map.end(); p++)
	{
		cout << p->first << ": " << p->second << endl;
		
	}
	
}

int main()
{


	//ResourceManager::ResourceManager("transactiondata/user-0.csv");
	std::string fileOne,fileTwo;
	cout << "Please enter the location of 1st user:" << flush;
	getline(cin, fileOne);

	ResourceManager callFunc;	
	// Will store the word and count.
	std::unordered_map<std::string, float> userOneInfo = callFunc.CategorizeIncExp(fileOne);
	// Print the words map.
	PrintMap(userOneInfo);



	cout << "Please enter the location of 1st user:" << flush;
	getline(cin, fileTwo);

	std::unordered_map<std::string, float> userTwoInfo = callFunc.CategorizeIncExp(fileTwo);
	PrintMap(userTwoInfo);



	
	cin.get();

	return EXIT_SUCCESS;
}


//// Begin reading from file:
//ifstream fileStream(fileName);

//// Check if we've opened the file (as we should have).
//if (fileStream.is_open())
//	while (fileStream.good())
//	{
//		// Store the next word in the file in a local variable.
//		string word;
//		fileStream >> word;

//		//Look if it's already there.
//		if (wordsCount.find(word) == wordsCount.end()) // Then we've encountered the word for a first time.
//			wordsCount[word] = 1; // Initialize it to 1.
//		else // Then we've already seen it before..
//			wordsCount[word]++; // Just increment it.
//	}
//else  // We couldn't open the file. Report the error in the error stream.
//{
//	cerr << "Couldn't open the file." << endl;
//	return EXIT_FAILURE;
//}

// Print the words map.
//PrintMap(wordsCount);
//cout << totalExpense << endl;




///*std::unordered_map<std::string, int> catergory = {
//	{"Paycheck",1},{"ACS - Student Loans",2},{"Amazon Order - Biology Book",2},{"Amazon Order - Mathematics Book",2},{"Amazon Order - Science Book",2},{"Online Education Courses",2},{"Navient - Student Loans",2},{"Library Membership",2},{"Mary's Book Store",2},{"Science Museum",2},
//	{"Amazon Order - Athletic Equipment",3},{"Athletic Apparel",3},{"Bowling",3},{"Dick's Sporting Goods",3},{"Ice Skating Rink",3},{"NBA Ticket - Lakers",3},{"NFL Ticket - Chargers",3},{"Sam's Sporting Apparel",3},
//	{"Coffee",4},{"Food Delivery - GrubHub",4},{"Food Delivery - Uber Eats",4},{"Restaurant - Burgers",4},{"Restaurant - Chinese",4},{"Restaurant - Pizza",4},{"Restaurant - Steakhouse",4},{"Starbucks Coffee",4},
//	{"Bike Rental",5},{"Public Transportation - Bus Pass",5},{"Public Transportation - Train Pass",5},{"Taxi",5},{"Uber",5},{"Lyft",5},
//	{"Amazon Order - Paint Bushes",6},{"Amazon Order - Paint Canvas",6},{"Art Auction",6},{"Art Museum",6},{"Art's Art Supplies",6},{"Ashley's Craft Store",6},{"Painting Course Fees",6},{"San Diego Museum",6},{"Michael's Crafts",6},
//	{"Guitar Center",7},{"Karaoke Bar",7},{"Music Lessons - Piano",7},{"Podcast Subscription",7},
//	{"Amazon Order - Star Wars Figurine",8},{"Concert Ticket",8},{"DVD - Star Trek",8},{"Movie Ticket",8},{"Netflix Subscription",8},{"On Demand Movie",8},{"On Demand TV",8},{"PlayStation Membership",8},{"Red Box DVD Rental",8},{"Video Game - PlayStation",8},
//	{"Amazon Order - Baby Crib",9},{"Babies R Us",9},{"BuyBuyBaby.com",9},{"Hospital - Prenatal Care",9},
//	{"Gas & Electric",10},{"Housing Rent",10},{"Von's Groceries",10},{"Water & Sewer",10},{"Whole Foods",10},{"Ralph's Grocery Store",10},{"Time Warner Cable",10},{"Credit Card Payment",10},
//	{"Pet Smart",11},{"Pet Supply - Cat Food",11},
//	{"Best Western Hotel",12},{"Cancun Beach Resort",12},{"Comfort Inn",12},
//	{"Total Gym Fees",13},{"GNC",13},{"Sprouts Market",13},{"Vitamin Shoppe",13},
//	{"Wine Bar",14},{"Wine Delivery",14},{"Green Flash Brewery",14},{"John's Bar & Restaurant",14},{"Owl Night Club",14},{"Rodriguez's Bar and Grill",14},{"Fisker Night Club",14},{"Seaside Bar",14},
//	{"Wedding Planner",15},{"Divorce Lawyer Fees",15},
//	{"Bank Fee - Negative Balance",16},{"Credit Card Overdraft Fee",16},{"Time Warne Cable - Late Payment Fee",16},{"Water & Sewer - Late Payment Penalty",16},{"Housing Rent - Late Fee",16},
//	{"FedEx Shipping",17},{"Goods2 - ThinkGeek",17},{"Hamilton Move & Storage",17},{"Home Depot",17},{"Jerome's Furniture",17},{"Kay Jewelry",17},{"Mark's Movers",17},{"Refrigerator Depot",17},{"Southwest Flights - Cancun",17}	
//};*/
//std::unordered_map<std::string, int> catergory = {
//	{ "Paycheck",1 },
//	{ "Babies R Us",2 }
//};

//

//std::string csv_File_name = "transactiondata/user-1.csv";
//std::ifstream  data(csv_File_name);
//std::string line;
//float totalExpense0=0.0f;
//float totalExpense1 = 0.0f;
//float totalExpense[2] = { 0.0f };
//



////skip the first line in the csv file
//std::getline(data, line);


//while (std::getline(data, line))
//{
//	std::stringstream  lineStream(line);
//	std::string        cell;
//	int column_count = 0;
//	

//	while (std::getline(lineStream, cell, ','))
//	{
//		column_count += 1;
//		string word;
//		float amount = 0.0f;
//		
//		// You have a cell!!!!
//		if (column_count == 3) {
//			word = cell;	
//			//to remove the double quotes from babies "r" us vendor name
//			word.erase(remove(word.begin(), word.end(), '\"'), word.end());
//		}
//				

//		std::unordered_map<std::string, int>::const_iterator got = catergory.find(word);
//		
//		if (got!=catergory.end())
//		{
//			//cout << word << endl;
//			std::getline(lineStream, cell, ',');
//			amount = std::stof(cell);				
//		}

//		switch (got->second)
//		{
//		case 1:totalExpense[0] += amount; // case 1 is total credit in the transactions
//			break;
//		case 2:totalExpense[1] += amount; // case 2 is irrelevent for now
//			break;

//		default:
//			break;
//		};
//			
//	}
//	
//}
/*std::cout << "paycheck " << totalExpense[0] << std::endl;
cout << "irrelevent" << totalExpense[1] << endl;*/