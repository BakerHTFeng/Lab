% lab1ʵ��
% �ر����д��ڣ��������������������д���
clear all;
close all;
clc;
% ��ȡͼ��
[file_name,path_name] = uigetfile('*.bmp;*.jpg','ѡ��ͼƬ');
A = imread([path_name,file_name]); 
% ��ͼչʾ����Ϊ��������
figure('name','lab_1');
    subplot(3,2,1);
        % ���ͼ���ǲ�ɫ�ģ���ת��Ϊ�Ҷ�ͼ��
        if size(A,3)>1
        	A = rgb2gray(A);
        end
        % չʾͼ��
        imshow(A);
        title('ԭͼ��');
    subplot(3,2,2);
        % ����ֱ��ͼ���Ҷȼ���ͼ���������
        bar(double(min(A(:)):1:max(A(:))),freq(A),'grouped');
        title('ֱ��ͼ');
    subplot(3,2,3);
        % hist_eqal��ͼ����⻯��imshow���
        he = hist_equal(A);
        imshow(he);
        title('���⻯���ͼ��');
    subplot(3,2,4);
        % ����ֱ��ͼ���Ҷȼ���ͼ���������
        bar(double(min(he(:)):1:max(he(:))),freq(he),'grouped');
        title('���⻯��ֱ��ͼ');
    subplot(3,2,5);
        % input_linear����cell{min,max,k,b}
        param = input_linear();
        % �Ҷ�����ʵ�֣�������(min,max)������ֵ��y = kx + b��������
        result = gray_extension(A,str2double(param{1,1}),str2double(param{2,1}),str2double(param{3,1}),str2double(param{4,1}));
        bar(min(result(:)):1:max(result(:)),freq(result),'grouped');
        imshow(uint8(result));
        title('�Ҷ������ͼ��');
    subplot(3,2,6);
        % ����ֱ��ͼ���Ҷȼ���ͼ���������
        bar(min(result(:)):1:max(result(:)),freq(result),'grouped');
        title('�Ҷ������ֱ��ͼ');