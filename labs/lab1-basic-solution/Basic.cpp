/*
* Gemfire Developer Native Client Course
* Lab1: Basic Gemfire API operations
*
* This example takes the following steps:
*
* 1. Create a GemFire Client Cache using configuraiton in the clientCache.xml file.
* 2. Obtains reference to the client region object that represents local handle to the remote server region
* 3. Puts simple string type key and value entry to the region
* 4. Puts simple integer type key and value entry to the region
* 5. Gets entries from the Region
* 6. Closes the Cache
*
* To complete the lab you need to fill in code at the places marked with TODO-:
* 
* TODO-0: Replace locator host IP address in the clientCache.xml file with the correct Gemfire cluster locator address 
* TODO-1: Include the GemFire library headers
* TODO-2: Use the "gemfire" namespace
* TODO-3: Create a CacheFactoryPtr instance 
* TODO-4: Use cacheFactory instance to create a GemFire Client Cache with configuration from the clientCache.xml file
* TODO-5: Use CachePtr client cache object to obtain reference to the client region object
* TODO-6: Use region object reference to put an key and value pair into the Region using the direct/shortcut method.
* TODO-7: Use CacheableInt32 to manually create put integer key and value into the Region
* TODO-8: Get CachablePtr from the region with the created entries back out of the Region
* TODO-9: Close client cache cachePtr object
* 
* 
*/


// TODO-1: Include the GemFire library headers
#include <gfcpp/GemfireCppCache.hpp>

using namespace std;
// TODO-2: Use the "gemfire" namespace
using namespace gemfire;

// The application main entry point
int main(int argc, char ** argv)
{
  try
  {
    // TODO-3: Create a CacheFactoryPtr instance 
    CacheFactoryPtr cacheFactory = CacheFactory::createCacheFactory();

    // TODO-4: Use cacheFactory instance to create a GemFire Client Cache with configuration from the clientCache.xml file
    CachePtr cachePtr = cacheFactory->set("cache-xml-file", "./clientCache.xml")->create();          

    LOGINFO("Created the GemFire Cache");

    // TODO-5: Use CachePtr client cache object to obtain reference to the client region "Customer" object
    RegionPtr regionPtr = cachePtr->getRegion("Customer");

    LOGINFO("Created Region");

    // TODO-6: Use region object reference to put an key and value pair into the Region using the direct/shortcut method
    regionPtr->put("Key1", "Value1");

    LOGINFO("Put the first Entry into the Region");

    // TODO-7: Use CacheableInt32 to manually create put integer key 123 and value into the Region
    CacheableKeyPtr keyPtr = CacheableInt32::create(123);

    CacheablePtr valuePtr = CacheableInt32::create(456);
    regionPtr->put(keyPtr, valuePtr);

    LOGINFO("Put the second Entry into the Region");

    // TODO-8: Get CachablePtr from the region with the created entries back out of the Region
    CacheableStringPtr result1Ptr = dynCast<CacheableStringPtr>(regionPtr->get("Key1"));
    LOGINFO( "Obtained the first Entry from the Region: %s", result1Ptr->toString() );


    CacheableInt32Ptr result2Ptr = dynCast<CacheableInt32Ptr>(regionPtr->get(keyPtr));
    LOGINFO( "Obtained the second Entry from the Region: %s", result2Ptr->toString()->toString() );


    // TODO-9: Close client cache cachePtr object
    cachePtr->close();

    LOGINFO("Closed the GemFire Cache");

  }// An exception should not occur
  catch(const Exception & gemfireExcp)
  {
    LOGERROR("DistributedSystem GemFire Exception: %s", gemfireExcp.getMessage());
  }
}
