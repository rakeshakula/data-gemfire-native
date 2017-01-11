#include <gfcpp/GemfireCppCache.hpp>
using namespace std;
using namespace gemfire;

int main(int argc, char ** argv)
{
  try
  {
    CacheFactoryPtr cacheFactory = CacheFactory::createCacheFactory();
    CachePtr cache = cacheFactory->set("cache-xml-file", "./clientCache.xml")->create();
    RegionPtr booksRegion = cache->getRegion("BookOrder");

    CacheablePtr fieldName = CacheableString::create("totalPrice");
    ResultCollectorPtr collector = FunctionService::onRegion(booksRegion)->withArgs(fieldName)->execute("GenericSumFunction");
    CacheableVectorPtr results = collector->getResult();

    for (int32_t i=0; i < results->size(); i++)
    {
      CacheableStringPtr item = dynCast<CacheableStringPtr>(results->operator[](i));
      LOGINFO("Result: %s", item->toString());
    }

    cache->close();

  }
  catch(const Exception & gemfireExcp)
  {
    LOGERROR("DistributedSystem GemFire Exception: %s", gemfireExcp.getMessage());
  }
}
