% lab2ʵ��
% �ر����д��ڣ��������������������д���
clear all;
close all;
clc;
figure('name','lab_2');
% ��ͨȥ��
    subplot(3,2,1);
    noise = imread('..\lena_noise.bmp');
    imshow(noise);
    title('����ͼ��');
    subplot(3,2,2);
    imshow (butterworth(noise,'lowp'));
    title('Butterworth��ͨ�˲�����ͼ��');
% ��ͨȥģ��
    subplot(3,2,3);
    blur = imread('..\lena_blur.bmp');
    imshow(blur);
    title('ģ��ͼ��');
    subplot(3,2,4);
    imshow (butterworth(blur,'highp'));
    title('Butterworth��ͨ�˲�����ͼ��');
% α��ɫ
    subplot(3,2,5);
    gray = imread('..\lena.jpg');
    imshow(gray);
    title('ԭͼ��');
    subplot(3,2,6);
% gray2index���Ҷ�ͼ��ת��Ϊ����ͼ��jetΪMATLABԤ���һ����ɫ����ɫ����ɫ��Ӧ������label2rgb������ͼ��ת��Ϊrgbͼ��
    prompt = {'Please enter n:'};
    param = inputdlg(prompt,'color',1,{'256'},'on');
    n = str2double(param{1,1});
    index = gray2index(gray, n);
    rgb = label2rgb(index,jet(n));
    imshow(rgb);
    title('α��ɫͼ');