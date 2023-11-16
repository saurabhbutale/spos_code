

#include "Operator.h"
#include<jni.h>
#include<iostream>
using namespace std;

 JNIEXPORT void JNICALL Java_Operator_add(JNIEnv*,jobject op,jint a,jint b)
    {
        cout<<"Addition: ";
        cout<<a+b<<endl;
    }
    
    JNIEXPORT void JNICALL Java_Operator_subtract(JNIEnv*,jobject op,jint a,jint b)
    {
        cout<<"Subtraction: ";
        cout<<a-b<<endl;
    }
    
    JNIEXPORT void JNICALL Java_Operator_multiply(JNIEnv*,jobject op,jint a,jint b)
    {
        cout<<"Multiplication: ";
        cout<<a*b<<endl;
    }
    
    JNIEXPORT void JNICALL Java_Operator_divide(JNIEnv*,jobject op,jint a,jint b)
    {
        cout<<"Division: ";
        cout<<a/b<<endl;
    }
    

