// RUN: %clang_cc1 -debug-info-kind=limited -emit-llvm -o - %s | FileCheck %s

static int a;

// CHECK-LABEL: define void @f
void f(int b) {
  a = b;
}

// CHECK: store i32 {{.*}} !dbg ![[artificialDbgLoc:[0-9]+]]

// CHECK: ![[artificialDbgLoc]] = !DILocation(line: 0
