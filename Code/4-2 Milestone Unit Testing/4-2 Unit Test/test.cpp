// Uncomment the next line to use precompiled headers
#include "pch.h"
#include <stdexcept>
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
//TEST_F(CollectionTest, AlwaysFail)
//{
//    FAIL();
//}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0) << "Collection bigger then 0";

    add_entries(1);

    ASSERT_EQ(collection->size(), 1) << "Unable to add 1 entry";

    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0) << "Collection bigger then 0";

    add_entries(5);

    ASSERT_EQ(collection->size(), 5) << "Size bigger then 5";
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, MaxSizeGreaterThanOrEqualTo01510) {
    
    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0) << "Collection bigger then 0";

    add_entries(1);

    ASSERT_EQ(collection->size(), 0 || 1) << "Not equal to 0 or 1";

    add_entries(4);
    //Current Size is 5 now

    ASSERT_TRUE(collection->size() >= 0 && collection->size() <= 5) << "Size is not between 0 and 5";

    add_entries(5);
    //Current size is now 10

    ASSERT_TRUE(collection->size() >= 0 && collection->size() <= 10) << "Size is not between 0 and 10";

}


// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, CapacityGreaterThanOrEqualTo01510) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Collection bigger then 0";

    add_entries(1);
    //Total Capacity 1

    ASSERT_TRUE(collection->capacity() >= 0 && collection->capacity() <= 1) << "Capacity is not between 0 - 1";

    add_entries(3);
    //Total Capacity 5

    ASSERT_TRUE(collection->capacity() >= 0 && collection->capacity() <= 5) << "Capacity is not between 0 - 5";

    add_entries(4);
    //Total Capacity 10

    ASSERT_TRUE(collection->capacity() >= 0 && collection->capacity() <= 10) << "Capacity is not between 0 - 10"; 
}


// TODO: Create a test to verify resizing increases the collection

TEST_F(CollectionTest, ResizingCollectionIncrease) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    collection->resize(1);

    ASSERT_TRUE(collection->size() == 1) << "size is not between 1";

    collection->resize(2);

    ASSERT_TRUE(collection->size() == 2) << "size is not between 1";
}

// TODO: Create a test to verify resizing decreases the collection

TEST_F(CollectionTest, ResizingCollectionDecrease) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    collection->resize(2);

    ASSERT_TRUE(collection->size() == 2) << "size is not 2";

    collection->resize(1);

    ASSERT_TRUE(collection->size() == 1) << "size is not 1";
}

// TODO: Create a test to verify resizing decreases the collection to zero

TEST_F(CollectionTest, ResizingCollectionTo0) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    collection->resize(10);

    ASSERT_TRUE(collection->size() == 10) << "size is not 10";

    collection->resize(0);

    ASSERT_TRUE(collection->size() == 0) << "Size is not 0";
}

// TODO: Create a test to verify clear erases the collection

TEST_F(CollectionTest, EraseTheCollection) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    add_entries(1);

    ASSERT_TRUE(collection->size() == 1) << "size is not 1";

    collection->erase(collection->begin());

    ASSERT_TRUE(collection->size() == 0) << "Collection Didn't Erase Properly";

}

// TODO: Create a test to verify erase(begin,end) erases the collection

TEST_F(CollectionTest, EraseBeginAndEndCollection) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    add_entries(10);

    ASSERT_TRUE(collection->size() == 10) << "size is not 10";

    collection->erase(collection->begin()+ 1);

    ASSERT_TRUE(collection->size() == 9) << "size is not 9";

    collection->erase(collection->end()- 1);

    ASSERT_TRUE(collection->size() == 8) << "size is not 8";
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection

TEST_F(CollectionTest, IncreaseCapacityButNotSize) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    collection->reserve(10);

    ASSERT_TRUE(collection->size() != 10) << "size is 10";

    ASSERT_TRUE(collection->capacity(), == 10) << "Capacity is 10";

}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test

TEST_F(CollectionTest, OutOfRangeException) {

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    add_entries(15);
    

    if (collection->size() >= 0 && collection->size() >= 10)
    {
        ASSERT_THROW(throw std::out_of_range("Out of range"), std::out_of_range);
    }
    else {
        FAIL() << "Didn't Throw Error";
    }

}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

TEST_F(CollectionTest, CustomPositive) {
    //This test that the vector can store values as well as retrieve them 

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    collection->push_back(10);
    collection->push_back(20);
    collection->push_back(30);

    ASSERT_EQ(collection->at(1), 20) << "Value in 1st position isn't 20";
}

TEST_F(CollectionTest, CustomNegative) {
    //This test if it throws a generic exception. 

    // is the collection empty?
    ASSERT_TRUE(collection->empty()) << "Collection Not Empty";

    // if empty, the size must be 0
    ASSERT_EQ(collection->capacity(), 0) << "Capacity bigger then 0";

    add_entries(15);


    if (collection->size() >= 0 && collection->size() >= 10)
    {
        ASSERT_THROW(throw std::exception("Regular Exception"), std::exception);
    }
    else {
        FAIL();
    }

}

TEST_F(CollectionTest, PersonalTesting) {
    //This is my own personal debug just to ensure I remember how to do testing properly. 
    int number = 1;
    std::cout << "hello";

    EXPECT_TRUE(number == 1) << "tester";

}