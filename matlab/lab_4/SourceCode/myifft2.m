function result = myifft2( list )
%MYIFFT2 ��ά���ٸ���Ҷ��任
%   ��M=N=2^nʱ�����ݹ�ʽ���ټ�������ά����Ҷ��任�Ľ��
    [x,y] = size(list);
    result = zeros(x,y);
     % ��ά����Ҷ��任�൱����x��y�Ϸֱ����һ��һά����Ҷ��任
    for i=1:x;
        result(i,:) = myifft(list(i,:));
    end
    for j=1:y;
        result(:,j) = myifft(result(:,j));
    end
    result = real(result);
end

function result = myifft( list )
%MYIFFT ���ٸ���Ҷ��任
%   ��N=2^nʱ�����ݹ�ʽ���ټ�����㸵��Ҷ��任�Ľ��
    N = length(list);
    % ȡԭ���еĹ�������
    list_conj = conj(list);
    % �Թ������н��п��ٸ���Ҷ�任
    result_conj = myfft(list_conj);
    % ���ȡ�������N
    result = conj(result_conj)/N;
end