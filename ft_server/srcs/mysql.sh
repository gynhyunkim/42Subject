#!/bin/bash

CREATE DATABASE wordpress;
CREATE USER 'gkim'@'localhost' identified by 'gkim1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'gkim'@'localhost';
USE wordpress;