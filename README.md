# Lab1 AK-2
## Listing of files:

* calculator.h
```
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    public:
        int Add (int, int);
        int Sub (double, double);
        int Mul (double, double);
};

#endif//CALCULATOR_H
```
* calculator.cpp
```
#include "calculator.h"

int Calculator::Add (double a, double b)
{
	return a + b + 0.5;
}

int Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}

int Calculator::Mul (double a, double b)
{
    return a * b + 0.5;
}


// I
// must 
// add
// some 
// changes
// and 
// commit 
// 'em
```
## Patches:

* 0001-fix-truncation-error.patch
```
From ae4b769dd05f1eaee022dec2f101bb50ff62ff31 Mon Sep 17 00:00:00 2001
From: Sergii Piatakov <sergii.piatakov@globallogic.com>
Date: Thu, 15 Nov 2018 15:28:04 +0200
Subject: [PATCH] fix truncation error

To convert float to integer the truncation is performed, but the
rounding is expected.

Test: Add (4.9, 4.9) should return 10.
Signed-off-by: Sergii Piatakov <sergii.piatakov@globallogic.com>
Signed-off-by: Eglantinee <twostepsfromoblivion@gmail.com>
---
 calculator.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/calculator.cpp b/calculator.cpp
index b91afea..d93e35b 100644
--- a/calculator.cpp
+++ b/calculator.cpp
@@ -2,7 +2,7 @@
 
 int Calculator::Add (double a, double b)
 {
-    return a + b;
+	return a + b + 0.5;
 }
 
 int Calculator::Sub (double a, double b)
-- 
2.28.0

```
* 0001-formatting-use-tabs-instead-of-spaces.patch
```
From f48b6813df93d94ddd1a7782dacc6992ffc1e6af Mon Sep 17 00:00:00 2001
From: Sergii Piatakov <sergii.piatakov@globallogic.com>
Date: Thu, 15 Nov 2018 15:26:35 +0200
Subject: [PATCH] formatting: use tabs instead of spaces

Signed-off-by: Sergii Piatakov <sergii.piatakov@globallogic.com>
Signed-off-by: Eglantinee <twostepsfromoblivion@gmail.com>
---
 calculator.cpp | 4 ++--
 calculator.h   | 6 +++---
 2 files changed, 5 insertions(+), 5 deletions(-)

diff --git a/calculator.cpp b/calculator.cpp
index d93e35b..f323e14 100644
--- a/calculator.cpp
+++ b/calculator.cpp
@@ -2,10 +2,10 @@
 
 int Calculator::Add (double a, double b)
 {
-	return a + b + 0.5;
+	return a + b;
 }
 
 int Calculator::Sub (double a, double b)
 {
-    return Add (a, -b);
+	return Add (a, -b);
 }
diff --git a/calculator.h b/calculator.h
index 3740907..d59d596 100644
--- a/calculator.h
+++ b/calculator.h
@@ -3,9 +3,9 @@
 
 class Calculator
 {
-    public:
-        int Add (double, double);
-        int Sub (double, double);
+	public:
+		int Add (double, double);
+		int Sub (double, double);
 };
 
 #endif//CALCULATOR_H
-- 
2.28.0

```
