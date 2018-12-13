//: Playground - noun: a place where people can play

import UIKit
let num = "22+33*99+11"
var symbol = false
/*
var index = str.index(of: "+")
let greeting = str[str.startIndex ..< index!]
index = str.index(index!, offsetBy: 1)  //空格位置往后移动一位
let name = str[index! ..< str.endIndex]
print(greeting)
print(name)*/
let deRange = num.range(of: "+" )
//let wholeNumber = num.prefix(upTo: deRange!.lowerBound)
let backNumber = num.suffix(from: deRange!.lowerBound)


if backNumber.contains("+")||backNumber.contains("-")||backNumber.contains("*")||backNumber.contains("/")
{
    symbol = true
    
}
else{
    symbol = false
}
while symbol {
    let wholeNumber = num.prefix(upTo: deRange!.lowerBound)
    print(wholeNumber)
    break
}

print(num)

