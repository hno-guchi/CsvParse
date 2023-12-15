cmake_minimum_required(VERSION 3.14)
project(MyProject)

# FetchContentモジュールを含むモジュールをインクルード
include(FetchContent)

# Google Testのダウンロードと設定
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# Windows環境で共有ランタイムを使用するための設定
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")

# Google Testをプロジェクトに組み込む
FetchContent_MakeAvailable(googletest)

# テスト対象の実行可能ファイルを作成
add_executable(CsvTest CsvTest.cpp Csv.cpp)

# テスト対象の実行可能ファイルに gtest_main ライブラリをリンク
target_link_libraries(CsvTest gtest_main)

# テストの登録
add_test(NAME CsvTest COMMAND CsvTest)
