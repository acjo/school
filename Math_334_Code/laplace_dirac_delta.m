clc 
clear all
close all
syms t s

laplace(cos(t)*dirac(t-2*pi), t, s)
