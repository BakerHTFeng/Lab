% lab4ʵ��
% �ر����д��ڣ��������������������д���
clear all;
close all;
clc;
% ��ȡͼ��
[file_name,path_name] = uigetfile('*.bmp;*.jpg','ѡ��ͼƬ');
img = imread([path_name,file_name]);
% ��ͼչʾ����Ϊ�������
figure('name','lab_3');
    subplot(3,2,1);
        % ���ͼ���ǲ�ɫ�ģ���ת��Ϊ�Ҷ�ͼ��
        if size(img,3)>1
        	img = rgb2gray(img);
        end
        % չʾͼ��
        imshow(img);
        title('ԭͼ��');
    subplot(3,2,3);
        my = myfft2(double(img));
        A = abs(fftshift(my));
        A=(A - min(A(:)))/(max(A(:))-min(A(:))) * 225;
        imshow(A);
        title('�Ա�fft2���');
    subplot(3,2,4);
        default = fft2(img);
        A = abs(fftshift(default));
        A=(A - min(A(:)))/(max(A(:))-min(A(:))) * 225;
        imshow(A);
        title('�Դ�fft2���');
    subplot(3,2,5);
        myresult = myifft2(my);
        imshow(uint8(myresult));
        title('�Ա�ifft2���');
    subplot(3,2,6);
        result = ifft2(default);
        imshow(uint8(result));
        k = result-myresult;
        title('�Դ�ifft2���');