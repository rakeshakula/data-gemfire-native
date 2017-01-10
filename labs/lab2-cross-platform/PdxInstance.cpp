/*
* Gemfire Developer Native Client Course
* Lab2: PDX serialization and cross-platform communication
*
* This example takes the following steps:
*
* 1. Create a PdxInstance object
* 2. Populates the PdxInstance object with the test value fields
* 3. Stores the PdxIsntance object in the Gemfire cache region
* 4. Retrieves the stored PdxIsntance object from the Gemfire cache region
* 5. Compares the PdxInstance field values to prove they were saved correctly
* 6. Reads PdxInstance object stored in the Gemfire cache region by a Java application
*
* To complete the lab you need to fill in code at the places marked with TODO-:
*
* TODO-0: In the clientPdxInstance.xml replace locator host IP address with the correct Gemfire
*         cluster locator address
* TODO-1: In the clientPdxInstance.xml add pdx element and set read-serailized flag to true
* TODO-2: Create an instance of the Person class to be stored in the Gemfire cache using PDX serialization
* TODO-3: Create PdxInstanceFactoryPtr object for the "Person" class
* TODO-4: Write Person's field "m_name" to the PdxInstanceFactoryPtr as String
* TODO-5: Write Person's field "m_id" to the PdxInstanceFactoryPtr as Integer
* TODO-6: Mark "m_id" field as PDX instance identity field
* TODO-7: Create PdxInstancePtr object from the PdxInstanceFactoryPtr
* TODO-8: Put the PdxInstancePtr object to the "Customer" region under key "Key3" as is
* TODO-9: Read the "Key3" from the "Customer" region as PdxInstancePtr object
* TODO-10: Read the "m_id", "m_age" and "m_name" fields from the PdxInstancePtr object
* TODO-11: Read the PdxInstancePtr object stored under key 9999 by the Java application
*	       from the main Gemfire Developer Course "Data Serialization" lab
* TODO-12: Read the "customerNumber", "firstName", "lastName", "telephoneNumber" fields
*	       of the retrieved PdxInstancePtr object
* TODO-13: In the application output ensure that the read values correspond to the ones stored
           in the Gemfire cache by the Java application from the "Data Serialization" lab
*
*/


#include <gfcpp/GemfireCppCache.hpp>

using namespace gemfire;

/*
 * This is first custom entity class, which instances we will be storing using PDX serialization
 */
class Person
{
private:
  const char* m_name;
  int m_id;
  int m_age;

public:
  Person() { }

  Person(const char* name, int id, int age)
  {
	m_name = name;
	m_id = id;
	m_age = age;
  }

  const char* getName() const
  {
	return m_name;
  }
  int getID()
  {
	return m_id;
  }
  int getAge()
  {
	return m_age;
  }
};


/*
 * This is a custom entity class that will be used to accept objects values stored in the cache
 * by a Java client application. Please refer to the Cahpter 11 of the main "Gemfire Developer Course"
 * for details.
 */
class Customer
{
private:
	int32_t m_customerNumber;
	const char* m_firstName;
	const char* m_lastName;
	const char* m_telephoneNumber;


public:
	Customer(){}
	Customer(const int32_t customerNumber, const char* firstName, const char* lastName, const char* telephoneNumber)
	{
		m_customerNumber = customerNumber;
		m_firstName = firstName;
		m_lastName = lastName;
		m_telephoneNumber = telephoneNumber;
	}

	int getCustomerNumber() const { return m_customerNumber; }
	const char* getFirstName() const { return m_firstName; }
	const char* getLastName() const { return m_lastName; }
	const char* getTelephoneNumber() const { return m_telephoneNumber; }
};


// The PdxInstance QuickStart example.
int main(int argc, char ** argv)
{
  try
  {
	// Create a GemFire Cache.
	CacheFactoryPtr cacheFactory = CacheFactory::createCacheFactory();

	CachePtr cachePtr = cacheFactory->set("cache-xml-file", "clientPdxInstance.xml")->create();

	LOGINFO("Created the GemFire Cache");

	// Get the example Region from the Cache which is declared in the Cache XML file.
	RegionPtr regionPtr = cachePtr->getRegion("Customer");
	LOGINFO("Obtained the Region from the Cache");

 	LOGINFO("******************* WORKING WITH PDX *******************");

 	// TODO-2: Create an instance of the Person class to be stored in the Gemfire cache using PDX serialization
	Person p...

	// TODO-3: Create PdxInstanceFactoryPtr object for the "Person" class
	PdxInstanceFactoryPtr pif = cachePtr->...
	LOGINFO("Created PdxInstanceFactory for Person class");

	// TODO-4: Write Person's field "m_name" to the PdxInstanceFactoryPtr as String
	pif->...
	// TODO-5: Write Person's field "m_id" to the PdxInstanceFactoryPtr as Integer
	pif->...
	// TODO-6: Mark "m_id" field as PDX instance identity field
	pif->...
	pif->writeInt("m_age", p.getAge());

	// TODO-7: Create PdxInstancePtr object from the PdxInstanceFactoryPtr
	PdxInstancePtr pdxInstance = pif->...

	LOGINFO("Created PdxInstance for Person class");

	// TODO-8: Put the PdxInstancePtr object to the "Customer" region under key "Key3" as is
	...

	LOGINFO("Populated PdxInstance Object");

	// TODO-9: Read the "Key3" from the "Customer" region as PdxInstancePtr object
	...

	LOGINFO("Got PdxInstance Object");

	// TODO-10: Read the "m_id", "m_age" and "m_name" fields from the PdxInstancePtr object
	int id = 0;
	int age = 0;
	char* name = NULL;

	// The check compares the field values of the retrieved object with the initial ones
	if(id == p.getID() && age == p.getAge() && strcmp(name, p.getName()) == 0
	 	&& retPdxInstance->isIdentityField("m_id")) {
	    LOGINFO("PdxInstance returns all fields value expected");
	}
	else {
	    LOGINFO("PdxInstance doesn't return all fields value expected");
	}


	LOGINFO("******************* READING JAVA VALUES *******************");

	// TODO-11: Read the PdxInstancePtr object stored under key 9999 by the Java application
	//          from the main Gemfire Developer Course "Data Serialization" lab
	PdxInstancePtr pdxCustomer = ...

	// TODO-12: Read the "customerNumber", "firstName", "lastName", "telephoneNumber" fields
	//          of the retrieved PdxInstancePtr object
	int32_t customerNumber = 0;
	char* firstName;
	char* lastName;
	char* telephoneNumber;

	// Build the local domain class object instance manually
	Customer cust(customerNumber, firstName, lastName, telephoneNumber);

	// TODO-13: In the application output ensure that the read values correspond to the ones stored
	//          in the Gemfire cache by the Java application from the "Data Serialization" lab
	LOGINFO( "Read Customer: customerNumber=%d; firstName=%s; lastName=%s; telephoneNumber=%s",
		customerNumber, cust.getFirstName(), cust.getLastName(), cust.getTelephoneNumber());


	cachePtr->close();
	LOGINFO("Closed the GemFire Cache");

  }
  // An exception should not occur
  catch(const Exception & gemfireExcp)
  {
	LOGERROR("PdxInstance GemFire Exception: %s", gemfireExcp.getMessage());
  }
}
