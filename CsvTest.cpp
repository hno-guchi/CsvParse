#include <gtest/gtest.h>
#include "./Csv.hpp"

TEST(CsvTest, BasicTest) {
	// テスト対象の関数を呼び出す
	Csv csv("./data.csv");

	// 期待される結果と比較
	std::string line("name,age");
	std::string result("");

	csv.getField(&result, &line);
	EXPECT_EQ(result, "name");

	csv.getField(&result, &line);
	EXPECT_EQ(result, "age");
}

// TEST(CsvTest, EmptyStringTest) {
//     // テスト対象の関数を呼び出す
//     std::string input = "";
//     std::vector<std::string> result = splitString(input);
//
//     // 期待される結果と比較
//     ASSERT_EQ(result.size(), 0);
// }
//
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
