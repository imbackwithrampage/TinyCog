/*
  File: RPC_Client.hpp
  Date: May, 2018
  Author: Dagim Sisay <dagiopia@gmail.com>
  License: AGPL
*/

#ifndef _RPC_CLIENT_HPP_
#define _RPC_CLIENT_HPP_

#include <iostream>
#include <string>
#include <vector>

#include <grpcpp/grpcpp.h>

#include <opencv2/opencv.hpp>

#include "img_base.grpc.pb.h"

#define SERVER_ADDRESS "@SERVER_ADDRESS@"
#define IMG_ENCODING ".jpg"

using grpc::Status;
using grpc::Channel;
using grpc::CreateChannel;
using grpc::ClientContext;


class RPC_Client
{    
    public:
      RPC_Client() : stub_(get_channel()) {}
      ~RPC_Client() {}


    private:
      std::unique_ptr<ImageBase::ImageServices::Stub> stub_;
      std::shared_ptr<Channel> channel;
      std::shared_ptr<Channel> get_channel() 
      {
          channel = CreateChannel(SERVER_ADDRESS, grpc::InsecureChannelCredentials());
          return ImageBase::ImageServices::NewStub(channel);
      };

      std::vector<unsigned char> vbuff;
      unsigned char *ucbuff;

      void encode_img(cv::Mat);

};


#endif //_RPC_CLIENT_HPP_
