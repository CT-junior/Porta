#include "Firebase.h"

void FireBase::init(){
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}