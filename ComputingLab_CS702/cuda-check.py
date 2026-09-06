import torch

# 1. Check if a GPU (CUDA) is available
if torch.cuda.is_available():
    print(f"GPU is available! Device name: {torch.cuda.get_device_name(0)}")
    
    # 2. Tell PyTorch to send your work to the GPU
    device = torch.device("cuda")
else:
    print("GPU is not available. Using CPU instead.")
    device = torch.device("cpu")

# 3. Example: Move a piece of data to your GPU
# (This makes calculations much faster)
my_data = torch.tensor([1.0, 2.0, 3.0])
my_data = my_data.to(device)
print(f"Data is now stored on: {my_data.device}")