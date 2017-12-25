#include <fstream>
#include <openssl/pem.h>
#include <openssl/rsa.h>

char *private_key_file_name = "private_key.pem";
char *encrypted_file_name = "encrypted_file";
char *decrypted_file_name = "decrypted_file";

int main()
{
    FILE *fp = fopen(private_key_file_name, "r");

    RSA *rsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);

    fclose(fp);

    std::ifstream enc_file;

    enc_file.open(encrypted_file_name, std::ifstream::in);

    int keysize = RSA_size(rsa);

    std::auto_ptr<unsigned char> rsa_in(new unsigned char[keysize * 2]);
    std::auto_ptr<unsigned char> rsa_out(new unsigned char[keysize]);

    memset(rsa_in.get(), 0, keysize * 2);
    memset(rsa_out.get(), 0, keysize);

    enc_file.read(reinterpret_cast<char *>(rsa_in.get()), keysize * 2);

    int rsa_inlen = enc_file.gcount();

    int rsa_outlen  = RSA_private_decrypt(
            rsa_inlen, rsa_in.get(), rsa_out.get(),
            rsa, RSA_PKCS1_PADDING);

    std::ofstream dec_file;

    dec_file.open(decrypted_file_name, std::ifstream::out);

    dec_file.write(reinterpret_cast<char *>(rsa_out.get()), rsa_outlen);

    enc_file.close();
    dec_file.close();

    RSA_free(rsa);

    return 0;
}