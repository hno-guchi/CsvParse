#include <gtest/gtest.h>
#include "./Csv.hpp"

TEST(CsvTest, BasicTest) {
	// テスト対象の関数を呼び出す
	Csv csv("./sample.csv");

	std::string line("");
	std::string result("");

	// 期待される結果と比較
	csv.getField(&result, &line);	EXPECT_EQ(result, "");

	line = "field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");

	line = ",field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "");

	line = "field,field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");

	line = ",field,field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");

	line = "field,,field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
}

TEST(CsvTest, ExceptionTest) {
	// テスト対象の関数を呼び出す
	Csv csv("./sample.csv");

	std::string	line("field,");
	std::string	result("");

    // 期待される結果と比較
	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);

	line = "field,field,";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
	result = "";
	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);

	line = ",,";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "");
	result = "";
	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);
}

// TEST(CsvTest, EmptyStringTest) {
//     // テスト対象の関数を呼び出す
//     std::string input = "";
//     std::vector<std::string> result = splitString(input);
//
//     // 期待される結果と比較
//     ASSERT_EQ(result.size(), 0);
// }

// TEST(SplitStringTest, MultipleSpacesTest) {
//     // テスト対象の関数を呼び出す
//     std::string input = "   This   is    a   test   ";
//     std::vector<std::string> result = splitString(input);
//
//     // 期待される結果と比較
//     ASSERT_EQ(result.size(), 4);
//     EXPECT_EQ(result[0], "This");
//     EXPECT_EQ(result[1], "is");
//     EXPECT_EQ(result[2], "a");
//     EXPECT_EQ(result[3], "test");
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
