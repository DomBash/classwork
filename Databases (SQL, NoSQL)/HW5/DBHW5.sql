#1 -
SELECT s.SalesPersonName, p.SalesPersonID, SUM(p.SalesPrice * p.Quantity) as TotalRevenue, d.YEAR
	FROM Fact_ProductSales p
    LEFT JOIN Dim_SalesPerson s
		ON p.SalesPersonID = s.SalesPersonID
	LEFT JOIN Dim_DATE d
		ON p.SalesDateKey = d.DateKey
	WHERE d.YEAR like "%12%"
	GROUP BY p.SalesPersonID
    ORDER BY SUM(p.SalesPrice * p.Quantity) desc;
    
#2 -
SELECT c.CustomerName, p.CustomerID, SUM(p.SalesPrice * p.Quantity) as TotalRevenue, d.YEAR
	FROM Fact_ProductSales p
    LEFT JOIN Dim_Customer c
		ON p.CustomerID = c.CustomerID
	LEFT JOIN Dim_DATE d
		ON p.SalesDateKey = d.DateKey
	WHERE d.YEAR like "%12%"
	GROUP BY p.CustomerID
    ORDER BY SUM(p.SalesPrice * p.Quantity) desc;
    
SELECT c.CustomerName, p.CustomerID, SUM(p.SalesPrice * p.Quantity) as TotalRevenue, d.YEAR
	FROM Fact_ProductSales p
    LEFT JOIN Dim_Customer c
		ON p.CustomerID = c.CustomerID
	LEFT JOIN Dim_DATE d
		ON p.SalesDateKey = d.DateKey
	WHERE d.YEAR like "%13%"
	GROUP BY p.CustomerID
    ORDER BY SUM(p.SalesPrice * p.Quantity) desc;
    
#3 -
SELECT p.StoreID, d.YEAR, SUM(p.SalesPrice * p.Quantity) as TotalRevenue
	FROM Fact_ProductSales p
    LEFT JOIN Dim_Date d
		ON p.SalesDateKey = d.DateKey
	GROUP BY p.StoreID, d.YEAR
    ORDER BY d.YEAR;
    
#4 -
SELECT p.ProductID, SUM((p.SalesPrice - p.ProductCost) * p.Quantity) as Profit, d.YEAR
	FROM Fact_ProductSales p
	LEFT JOIN Dim_DATE d
		ON p.SalesDateKey = d.DateKey
	WHERE d.YEAR like "%15%"
	GROUP BY p.ProductID
	ORDER BY SUM((p.SalesPrice - p.ProductCost) * p.Quantity) desc;
    
#5 -
SELECT d.Quarter, SUM(p.SalesPrice * p.Quantity) as TotalRevenue, s.City
	FROM Fact_ProductSales p
    LEFT JOIN Dim_Store s
		ON p.StoreID = s.StoreID
	LEFT JOIN Dim_Date d
		ON p.SalesDateKey = d.DateKey
	WHERE s.City like "%Boulder%"
    AND d.YEAR like "%16%"
    GROUP BY d.Quarter;
