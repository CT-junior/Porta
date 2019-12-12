#ifndef FIREBASE_H
#define FIREBASE_H

#include <IOXhop_FirebaseESP32.h>                                                   // firebase library
#define FIREBASE_HOST "porta-ct.firebaseio.com/"                                    // the project name address from firebase id
#define FIREBASE_AUTH "TMburbSkLzJzZ7FekyNhz7YDiZzPYHHHZbvMykzv"                    // the secret key generated from firebase


class FireBase{
     public:
          void init();
};

#endif
