#include <gtest/gtest.h>
#include "./Csv.hpp"

TEST(CsvTest, getFieldTest) {
	// テスト対象の関数を呼び出す
	Csv			csv("./sample.csv");
	std::string	line("");
	std::string	result("");

	// 期待される結果と比較
	csv.getField(&result, &line);	EXPECT_EQ(result, "");

	line = "field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");

	line = "field,field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "field");

	line = ",field";
	result = "";
	csv.getField(&result, &line);	EXPECT_EQ(result, "");
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

TEST(CsvTest, setRecordTest) {
	// テスト対象の関数を呼び出す
	Csv			csv("./sample.csv");
	std::string	line("");

	// 期待される結果と比較
	line = ",";
	EXPECT_THROW(csv.setRecord(&line), Csv::ValidErr);

	line = ",,";
	EXPECT_THROW(csv.setRecord(&line), Csv::ValidErr);

	line = "field,field,";
	EXPECT_THROW(csv.setRecord(&line), Csv::ValidErr);

	line = "";
	EXPECT_NO_THROW(csv.setRecord(&line));
}

// TEST(CsvTest, ExceptionTest) {
// 	// テスト対象の関数を呼び出す
// 	Csv csv("./sample.csv");
//
// 	std::string	line("field,");
// 	std::string	result("");
//
//     // 期待される結果と比較
// 	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);
//
// 	line = "field,field,";
// 	result = "";
// 	csv.getField(&result, &line);	EXPECT_EQ(result, "field");
// 	result = "";
// 	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);
//
// 	line = ",,";
// 	result = "";
// 	csv.getField(&result, &line);	EXPECT_EQ(result, "");
// 	result = "";
// 	EXPECT_THROW(csv.getField(&result, &line), Csv::ValidErr);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
