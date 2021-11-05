FROM ubuntu:focal
MAINTAINER Kevin Buffardi (kbuffardi@csuchico.edu)
LABEL title="cxxTestIO"
LABEL version=0.1
WORKDIR /usr/src/cxxTestIO

# Install dependencies
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update &&  \
    apt-get install -y \
            build-essential \
            g++ \
            cmake \
            git-all \
            cxxtest

ADD * /usr/src/cxxTestIO
