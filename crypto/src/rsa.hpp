#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

class C_RSA {
    private:
        RSA *keypair;
        //internal encrypting/decrypting function
        int _encrypt(int len, unsigned char* data, unsigned char* out) {
            return RSA_public_encrypt(len, data, out, keypair, RSA_PKCS1_OAEP_PADDING);
        }

        int _decrypt(int len, unsigned char* enc, unsigned char* out){
            return RSA_private_decrypt(len, enc, out, keypair, RSA_PKCS1_OAEP_PADDING);
        }

        std::vector<unsigned char*> _split(std::string st) {
            size_t minsize = s.size()/count;
            int extra = s.size() - minsize * count;
            std::vector<unsigned char*> tokens;
            for(size_t i = 0, offset=0 ; i < count ; ++i, --extra)
            {
                size_t size = minsize + (extra>0?1:0);
                if ( (offset + size) < s.size())
                    tokens.push_back(s.substr(offset,size).c_str());
                else
                    tokens.push_back(s.substr(offset, s.size() - offset).c_str());
                    offset += size;
            }
            return tokens;
        }

    public:
        C_RSA(int bytes, int e);
        std::string encrypt(std::string s);
        std::string decrypt(std::string e);
}

C_RSA::C_RSA(int bytes = 4096, int e = 65537) {
    keypair = RSA_generate_key(bytes, e, NULL, NULL);
}

std::string C_RSA::encrypt(std::string s) {

}

