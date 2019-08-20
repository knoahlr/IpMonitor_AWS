
#define WIN32_LEAN_AND_MEAN
#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h> 
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/CreateTableRequest.h>
#include <aws/dynamodb/model/KeySchemaElement.h>
#include <aws/dynamodb/model/ProvisionedThroughput.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/GetItemRequest.h>
#include <aws/dynamodb/model/ListTablesRequest.h>
#include <aws/dynamodb/model/ListTablesResult.h>
#include <aws/dynamodb/model/QueryRequest.h>
#include <aws/dynamodb/model/ScanRequest.h>
#include <aws/dynamodb/model/ScanResult.h>

#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QHBoxLayout>

#include <iostream>
#include <chrono>


#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/beast/http.hpp>
#include <boost/regex.hpp>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdexcept>
#include <list>
using boost::asio::ip::tcp;

class Session
{

public:

	typedef struct ipItem{
		std::string Ip;
		std::string Date;
	}ipItem;

	std::list<ipItem> IPs;

	///<summary>
	/// AWS Session Object Handler
	///</summary>
	Session();
	Aws::DynamoDB::DynamoDBClient *dynamoDbClient;
	Aws::String Region = "us-east-2";

	Aws::DynamoDB::Model::PutItemRequest pir;

	Aws::DynamoDB::Model::GetItemRequest req;

	Aws::DynamoDB::Model::PutItemOutcome putResult;

	Aws::DynamoDB::Model::GetItemOutcome getResult;

	Aws::DynamoDB::Model::ListTablesRequest ltr;

	Aws::DynamoDB::Model::ListTablesOutcome lto;

	Aws::DynamoDB::Model::QueryRequest *queryReq;

	Aws::DynamoDB::Model::ScanRequest *scanRequest;

	Aws::DynamoDB::Model::ScanOutcome scanOC;

	Aws::DynamoDB::Model::QueryOutcome qoc;

	Aws::String _tableName = "IpMonitor";

	Aws::String _ipAttribute = "Ip";

	Aws::String _dateAttribute = "Date";

	Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue> _item;

	Aws::DynamoDB::Model::AttributeValue setAttValue;

	Aws::DynamoDB::Model::AttributeValue getAttValue;


	void initializeSession();
	void clientConfiguration();
	void addIp();
	void getTables();
	void getItems();
	std::tuple <Aws::String, Aws::String>getIPandDate();
	Aws::String queryIP();

};