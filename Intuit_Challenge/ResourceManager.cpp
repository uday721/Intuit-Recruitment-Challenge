#include "ResourceManager.h"

std::unordered_map<std::string, float> ResourceManager::CategorizeIncExp(string fileName)
{
	const int numOfCategories = 17;
	std::string csv_File_name = fileName;
	std::ifstream data(csv_File_name);
	std::string line;
	
	//std::vector<int> totalExpense;
	float totalExpense[numOfCategories] = { 0.0f };
	
	const string categoryNames[numOfCategories] = { "Credit","Education","Sports","Food and Dining","Transportation","Art","Music","Entertainment","Baby Products","House and Maintenance","Pets","Accomodation","Health","Wine and Bars","Weddings and Divorse","Late Payment","Other Expenses" };

	std::unordered_map<std::string, int> catergory = {
	{"Paycheck",1},{"ACS - Student Loans",2},{"Amazon Order - Biology Book",2},{"Amazon Order - Mathematics Book",2},{"Amazon Order - Science Book",2},{"Online Education Courses",2},{"Navient - Student Loans",2},{"Library Membership",2},{"Mary's Book Store",2},{"Science Museum",2},
	{"Amazon Order - Athletic Equipment",3},{"Athletic Apparel",3},{"Bowling",3},{"Dick's Sporting Goods",3},{"Ice Skating Rink",3},{"NBA Ticket - Lakers",3},{"NFL Ticket - Chargers",3},{"Sam's Sporting Apparel",3},
	{"Coffee",4},{"Food Delivery - GrubHub",4},{"Food Delivery - Uber Eats",4},{"Restaurant - Burgers",4},{"Restaurant - Chinese",4},{"Restaurant - Pizza",4},{"Restaurant - Steakhouse",4},{"Starbucks Coffee",4},
	{"Bike Rental",5},{"Public Transportation - Bus Pass",5},{"Public Transportation - Train Pass",5},{"Taxi",5},{"Uber",5},{"Lyft",5},
	{"Amazon Order - Paint Bushes",6},{"Amazon Order - Paint Canvas",6},{"Art Auction",6},{"Art Museum",6},{"Art's Art Supplies",6},{"Ashley's Craft Store",6},{"Painting Course Fees",6},{"San Diego Museum",6},{"Michael's Crafts",6},
	{"Guitar Center",7},{"Karaoke Bar",7},{"Music Lessons - Piano",7},{"Podcast Subscription",7},
	{"Amazon Order - Star Wars Figurine",8},{"Concert Ticket",8},{"DVD - Star Trek",8},{"Movie Ticket",8},{"Netflix Subscription",8},{"On Demand Movie",8},{"On Demand TV",8},{"PlayStation Membership",8},{"Red Box DVD Rental",8},{"Video Game - PlayStation",8},
	{"Amazon Order - Baby Crib",9},{"Babies R Us",9},{"BuyBuyBaby.com",9},{"Hospital - Prenatal Care",9},
	{"Gas & Electric",10},{"Housing Rent",10},{"Von's Groceries",10},{"Water & Sewer",10},{"Whole Foods",10},{"Ralph's Grocery Store",10},{"Time Warner Cable",10},{"Credit Card Payment",10},
	{"Pet Smart",11},{"Pet Supply - Cat Food",11},
	{"Best Western Hotel",12},{"Cancun Beach Resort",12},{"Comfort Inn",12},
	{"Total Gym Fees",13},{"GNC",13},{"Sprouts Market",13},{"Vitamin Shoppe",13},
	{"Wine Bar",14},{"Wine Delivery",14},{"Green Flash Brewery",14},{"John's Bar & Restaurant",14},{"Owl Night Club",14},{"Rodriguez's Bar and Grill",14},{"Fisker Night Club",14},{"Seaside Bar",14},
	{"Wedding Planner",15},{"Divorce Lawyer Fees",15},
	{"Bank Fee - Negative Balance",16},{"Credit Card Overdraft Fee",16},{"Time Warne Cable - Late Payment Fee",16},{"Water & Sewer - Late Payment Penalty",16},{"Housing Rent - Late Fee",16},
	{"FedEx Shipping",17},{"Goods2 - ThinkGeek",17},{"Hamilton Move & Storage",17},{"Home Depot",17},{"Jerome's Furniture",17},{"Kay Jewelry",17},{"Mark's Movers",17},{"Refrigerator Depot",17},{"Southwest Flights - Cancun",17}
	};

	std::unordered_map<std::string, float> parsedData;

	//skip the first line in the csv file
	std::getline(data, line);

	while (std::getline(data, line)) {
		std::stringstream  lineStream(line);
		std::string        cell;
		int column_count = 0;


		while (std::getline(lineStream, cell, ',')) {
			column_count += 1;
			string word;
			float amount = 0.0f;

			// You have a cell!!!!
			if (column_count == 3) {
				word = cell;
				//to remove the double quotes from babies "r" us vendor name
				word.erase(remove(word.begin(), word.end(), '\"'), word.end());

			}

			if (column_count == 4) {
				amount = std::stof(cell);
				//cout << amount << endl;
				//totalExpense = totalExpense + amount;			
			}


			std::unordered_map<std::string, int>::const_iterator got = catergory.find(word);

			if (got != catergory.end()){
				std::getline(lineStream, cell, ','); // getting the corresponding amount of the vendor
				amount = std::stof(cell);
			}

			switch (got->second)
			{
			case 1:totalExpense[0] += amount; // case 1 is total credit in the transactions
				break;
			case 2:totalExpense[1] += amount; // case 2 is total money spent on education
				break;
			case 3:totalExpense[2] += amount; // case 3 is total money spent on sports and accessories
				break;
			case 4:totalExpense[3] += amount; // case 4 is total money spent on food and dining
				break;
			case 5:totalExpense[4] += amount; // case 5 is total money spent on transportation
				break;
			case 6:totalExpense[5] += amount; // case 6 is total money spent on arts
				break;
			case 7:totalExpense[6] += amount; // case 7 is total money spent on music
				break;
			case 8:totalExpense[7] += amount; // case 8 is total money spent on entertainment
				break;
			case 9:totalExpense[8] += amount; // case 9 is money spent on baby products
				break;
			case 10:totalExpense[9] += amount; // case 10 is money spent on house and maintenance
				break;
			case 11:totalExpense[10] += amount; // case 11 is money spent on pets
				break;
			case 12:totalExpense[11] += amount; // case 12 is money spent on accomodation
				break;
			case 13:totalExpense[12] += amount; // case 13 is money spent on health
				break;
			case 14:totalExpense[13] += amount; // case 14 is money spent on wines and bars
				break;
			case 15:totalExpense[14] += amount; // case 15 is money spent on wedding and divorse
				break;
			case 16:totalExpense[15] += amount; // case 16 is late payments
				break;
			case 17:totalExpense[16] += amount; // case 17 is other expenses
				break;
			default:
				break;
			};
		}
	}
	for (unsigned int i = 0; i < sizeof(totalExpense); i++)
	{
		parsedData.insert({ categoryNames[i],totalExpense[i]});
	}
	

	return parsedData;
}
