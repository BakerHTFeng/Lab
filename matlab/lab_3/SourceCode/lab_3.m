% lab3ʵ��
% �ر����д��ڣ��������������������д���
clear all;
close all;
clc;
% ��ȡͼ��
[file_name,path_name] = uigetfile('*.bmp;*.jpg','ѡ��ͼƬ');
A = imread([path_name,file_name]);
% ��ͼչʾ����Ϊ�������
figure('name','lab_3');
    subplot(3,2,1);
        % ���ͼ���ǲ�ɫ�ģ���ת��Ϊ�Ҷ�ͼ��
        if size(A,3)>1
        	A = rgb2gray(A);
        end
        % չʾͼ��
        imshow(A);
        title('ԭͼ��');
    subplot(3,2,3);
        % sobel����
        imshow(edgdet(A,'sobel'));
        title('Sobel���ӱ�Ե��ȡ');
    subplot(3,2,4);
        % prewitt����
        imshow(edgdet(A,'prewitt'));
        title('Prewitt���ӱ�Ե��ȡ');
    subplot(3,2,5);
        % roberts����
        imshow(edgdet(A,'roberts'));
        title('Roberts���ӱ�Ե��ȡ');
    subplot(3,2,6);
        % marr����
        imshow(edgdet(A,'marr'));
        title('Marr');