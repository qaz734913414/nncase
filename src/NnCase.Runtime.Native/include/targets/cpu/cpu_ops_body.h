#pragma once
#include "../node_body.h"

namespace nncase
{
namespace targets
{
    namespace cpu
    {
        struct cpu_conv2d_options
        {
            memory_range input;
            memory_range output;
            runtime_shape_t in_shape;
            int32_t out_channels;
            padding padding_h;
            padding padding_w;
            int32_t filter_h;
            int32_t filter_w;
            int32_t stride_h;
            int32_t stride_w;
            int32_t dilation_h;
            int32_t dilation_w;
            value_range<float> fused_activation;
            xtl::span<const float> weights;
            xtl::span<const float> bias;

            void deserialize(runtime::span_reader &reader)
            {
                reader.read(input);
                reader.read(output);
                reader.read(in_shape);
                reader.read(out_channels);
                reader.read(padding_h);
                reader.read(padding_w);
                reader.read(filter_h);
                reader.read(filter_w);
                reader.read(stride_h);
                reader.read(stride_w);
                reader.read(dilation_h);
                reader.read(dilation_w);
                reader.read(fused_activation);
                reader.read_span(weights, out_channels * in_shape[3] * filter_h * filter_w);
                reader.read_span(bias, out_channels);
            }
        };

        struct cpu_depthwise_conv2d_options
        {
            memory_range input;
            memory_range output;
            runtime_shape_t in_shape;
            padding padding_h;
            padding padding_w;
            int32_t filter_h;
            int32_t filter_w;
            int32_t stride_h;
            int32_t stride_w;
            int32_t dilation_h;
            int32_t dilation_w;
            value_range<float> fused_activation;
            xtl::span<const float> weights;
            xtl::span<const float> bias;

            void deserialize(runtime::span_reader &reader)
            {
                reader.read(input);
                reader.read(output);
                reader.read(in_shape);
                reader.read(padding_h);
                reader.read(padding_w);
                reader.read(filter_h);
                reader.read(filter_w);
                reader.read(stride_h);
                reader.read(stride_w);
                reader.read(dilation_h);
                reader.read(dilation_w);
                reader.read(fused_activation);
                reader.read_span(weights, in_shape[3] * filter_h * filter_w);
                reader.read_span(bias, in_shape[3]);
            }
        };

        struct cpu_reduce_window2d_options : simple_node_body<cpu_reduce_window2d_options>
        {
            memory_range input;
            memory_range output;
            reduce_op reduce_op;
            runtime_shape_t in_shape;
            padding padding_h;
            padding padding_w;
            int32_t filter_h;
            int32_t filter_w;
            int32_t stride_h;
            int32_t stride_w;
            int32_t dilation_h;
            int32_t dilation_w;
            float init_value;
            value_range<float> fused_activation;
        };
    }
}
}