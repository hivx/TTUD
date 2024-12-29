// Description
// Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
// Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
// Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
// Input
// Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
// Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
// Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
// Output
// Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

// Example
// Input
// 6 6
// 10 2
// 30 1
// 50 1
// 20 3
// 30 1
// 20 1
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 4 6
// Output
// 30

// Giải thích: 
// -Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
// -Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
// Tổng cộng mất 10 + 20 = 30 đồng