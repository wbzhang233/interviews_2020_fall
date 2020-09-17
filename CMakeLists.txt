cmake_minimum_required(VERSION 3.14)
project(interviews)

set(CMAKE_CXX_STANDARD 14)

add_executable(ls 1-0731Kedaxunfei/leastSquare.cpp)
add_executable(pdd 3-pinduoduo/pdd.cpp)
add_executable(bagProblem 3-pinduoduo/bagProblem.cpp)
add_executable(pdd2020_5 3-pinduoduo/pdd2020_5.cpp)
add_executable(jd1 4-JD/jd1.cpp)
add_executable(sortStr ./6-meituan2020/2020_3.cpp)
add_executable(issTest ./6-meituan2020/istringstreamTest.cpp)
add_executable(reloadOperator ./6-meituan2020/reloadOperator.cpp)

## bilibili
add_executable(bili1 7-bilibili/1.cpp)
add_executable(bili2 7-bilibili/2.cpp)
add_executable(bili22 7-bilibili/22.cpp)
add_executable(bili3 7-bilibili/3.cpp)
add_executable(bili32 7-bilibili/32.cpp)

## tencent0823
add_executable(tc1 tencent/1.cpp)
add_executable(tc4 tencent/4.cpp)
add_executable(tc41 tencent/4-1.cpp)
add_executable(tc42 tencent/4-2.cpp)
add_executable(tc5 tencent/5.cpp)

## huiding
add_executable(hd1 huiding/1.cpp)

## shopee
add_executable(sp1 shopee/1.cpp)
add_executable(sp2 shopee/2.cpp)

## ali0901
add_executable(ali1 ali0901/ali1.cpp)
add_executable(ali2 ali0901/2.cpp)

## qianxin
add_executable(qax1 qianxin/1.cpp)
add_executable(qax2 qianxin/21.cpp)

## baidu0903
add_executable(baidu1 baidu0903/1.cpp)
add_executable(baidu2 baidu0903/2.cpp)

## tencent0906
add_executable(tc0906-1 tencent0906/1.cpp)
add_executable(tc0906-2 tencent0906/2.cpp)
add_executable(tc0906-3 tencent0906/3.cpp)
add_executable(tc0906-4 tencent0906/4.cpp)

## nvidia
add_executable(nvidia1 nvidia0907/1.cpp)

## glodan
add_executable(glodan glodon/glodon.cpp)
add_executable(glodan3 glodon/glodon3.cpp)

## amazon
add_executable(amazon1 amazon/1.cpp)

add_executable(yfd1 yuanfudao0912/1.cpp)
add_executable(yfd3 yuanfudao0912/3.cpp)

# heapSort
add_executable(heapSort heapSort.cpp)

# yitu
add_executable(yitu yitu/yitu.cpp)
add_executable(yitu2 yitu/yitu2.cpp)
add_executable(yitu3 yitu/yitu3.cpp)
